a<-10
b<-100
a+b
#isto é um comentário
print("muy guapa mamacita")
data.frame(nome = c("Ana","Bruno"),idade=c(28,35))
matrix(1:9, nrow = 3, ncol = 3)
list(vetor = 1:3, matriz = matrix(1:4,2), df = data.frame(x=1))
idades<-c(22,20,20,22)
str(idades)
mean(idades)
matriz<-matrix(c(22,20,20,20),2,2)
dados<-data.frame(nome=c("Marco","Vitor","Tomás","João"),
                   signo=c("aquário","peixes","gemeos","carneiro"),
                   cidade=c("vieira","braga","famalicao","trofa"),
                   altura=c(1.84,1.72,1.80,1.80))
dados
str(dados)
summary(dados)
dim(dados)
dados[2,]
dados[3,]
dados[,3]
dados[1,3]
dados[2:4,]

x<-3
if(x>0){
  print("Positivo")
}else{
  print("Não positivo")
}
write.csv(dados,"saida.csv",row.names = FALSE)
dados
dados[dados$altura>1.8,]


library(dplyr)
dados%>% filter(altura>1.8)

dados$pe<-c(44,42,40.5,44)
dados
plot(dados$altura,dados$pe)

library(ggplot2)
ggplot(dados,aes(x=altura, y=pe)) +
  geom_point()+
  labs(title="relação entre altura e pé")
mtcars
