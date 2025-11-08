library(ggplot2)
library(tidyr)
library(tidyverse)
library(palmerpenguins)

# Exercicio 1
peng <- penguins |> drop_na(flipper_length_mm, bill_length_mm)

ggplot(peng, aes(x = flipper_length_mm, y = bill_depth_mm)) +
  geom_point()

modelo <- lm(flipper_length_mm ~ bill_length_mm, data = peng)

summary(modelo)

"
O modelo mostra uma relação positiva e estatisticamente significativa entre bill_length_mm e a variável dependente.
A cada aumento de 1 mm no comprimento do bico, espera-se um aumento médio de 1.69 unidades na outra variável.
O modelo explica cerca de 43% da variação observada, o que sugere uma relação relevante, mas não perfeita.
"
predict(modelo, newdata = data.frame(bill_length_mm = 45), 
        interval = "prediction", level = 0.95)

par(mfrow = c(2, 2))
plot(modelo)
par(mfrow = c(1, 1))

"
No grafico Residuals vs Fitted, os residuos estao dispersos porém perto da linha vermelha
No grafico Q-Q Residuals podemos ver que está bem uniforme segue uma diagonal
No grafico Scale-Location tambem 
Há alguns pontos com leverage mais alto, mas nenhum ultrapassa a linha de Cook’s distance 
portanto, não há outliers problemáticos evidentes.



Os resíduos estão próximos de uma distribuição normal,
A variância é relativamente constante,
E não há observações extremamente influentes.
Há, contudo, uma ligeira curvatura nos resíduos vs ajustados,
o que pode indicar pequena violação da suposição de linearidade.
"

# Exercicio 2 

data(diamonds, package = "ggplot2")

ggplot(diamonds, aes(x = price, y = carat))+
  geom_point()+
  geom_smooth(method = "lm", se = FALSE, color = "red")

modelo2 <- lm(price ~ carat, data = diamonds)
par(mfrow= c(2,2))
plot(modelo2)
par(mfrow = c(1,1))
summary(modelo2)$r.squared

modelo2_log <- lm(log(price) ~ log(carat), data = diamonds)
par(mfrow = c(2, 2))
plot(modelo2_log)
par(mfrow = c(1, 1))

"
O modelo sem log apresenta residuos mais bem-comportados
"

predict(modelo2, newdata = data.frame(carat = 1.0), 
        interval = "prediction", level = 0.95)

# Exercicio 3 
library(gapminder)
View(gapminder)

ano_2007 <- gapminder |>
  filter(year == 2007) |>
  select(lifeExp,gdpPercap)

ggplot(ano_2007, aes(x = lifeExp, y = log(gdpPercap))) +
  geom_point()

modeloa <- lm(lifeExp ~ gdpPercap, data = ano_2007)
par(mfrow = c(2, 2))
plot(modeloa)
par(mfrow = c(1, 1))
summary(modeloa)
modelob <- lm(lifeExp ~ log(gdpPercap), data = ano_2007)
par(mfrow = c(2, 2))
plot(modelob)
par(mfrow = c(1, 1))
summary(modelob)

"
Declive sem log -> 6.371e-04
Declive com log -> 7.2028
Interpretação → aumento de ~7,2 anos na esperança de vida para cada ´
aumento unitário no log do PIB per capita.
"

# Exercicio 4 
library(nycflights13)
View(flights)
voos <- flights |>
  filter(year == 2013) |>
  drop_na()

ggplot(voos, aes(x = dep_delay, y = distance)) +
  geom_point() +
  geom_smooth(method = "lm", se = FALSE, color = "red")

model <-lm(dep_delay ~ distance, data = voos)
summary(model)

"
O declive é -1.180e-03 
Para cada aumento de 1 milha na distância do voo, o atraso 
médio na partida diminui cerca de 1.180e-03 minutos
"
par(mfrow = c(2, 2))  
plot(model)
par(mfrow = c(1, 1))  

# Exercicio 5
ggplot2::diamonds
library(ggplot2)
library(dplyr)

names(diamonds)
View(diamonds)
nivelideal <- diamonds |>
  filter(cut == "Ideal")
nivelGood <- diamonds |>
  filter(cut == "Good")
modelideal <- lm(price~carat, data = nivelideal)
modelGood <- lm(price~carat, data = nivelGood)

par(mfrow = c(2,2))
plot(modelideal)
par(mfrow = c(1,1))

par(mfrow = c(2,2))
plot(modelGood)
par(mfrow = c(1,1))

# Exercicio 6 

library(broom)
subcuts <- c("Ideal","Good")
dsub <- diamonds |> filter(cut %in% subcuts)

mods_by_cut <- dsub |>
  group_by(cut) |>
  group_map(~ lm(price ~ carat, data = .x), keep = TRUE)

# Tabela comparativa das inclinações e R2 por subgrupo
tbl_slopes <- dsub |>
  group_by(cut) |>
  do(tidy(lm(price ~ carat, data = .))) |>
  filter(term == "carat") |>
  select(cut, estimate, std.error, p.value)

tbl_fit <- dsub |>
  group_by(cut) |>
  do(glance(lm(price ~ carat, data = .))) |>
  select(cut, r.squared, adj.r.squared, sigma)

list(tbl_slopes = tbl_slopes, tbl_fit = tbl_fit)

# Resíduos por subgrupo
par(mfrow=c(1,2))
plot(lm(price ~ carat, data = filter(dsub, cut=="Ideal")), which = 1, main = "Ideal: Resíduos vs Ajustados")
plot(lm(price ~ carat, data = filter(dsub, cut=="Good")),  which = 1, main = "Good: Resíduos vs Ajustados")

par(mfrow=c(1,1))
# ------------------------- //----------------------------

nivel <- diamonds |>
  filter(cut %in% c("Ideal","Good"))

sep <- nivel |>
  group_by(cut) |>
  group_map(~ lm(price ~ carat, data = .x), keep = TRUE)

