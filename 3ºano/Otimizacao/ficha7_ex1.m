syms w1 w2 w3 y1;

F = w1^2 - 2w1+w2^2-w3^2+4w3;
c1 = w1-w2+2w3-2;

%Defeinir teorema de Lagrange
L = F-y1*c1;

%Verificar se o ponto é admissivel w = (2.5,-1.5,-1)
c1ad = subs(c1,[w1 w2 w3],[2.5 -1.5 -1]);

%verificar se w é regular, como neste caso so tem uma restricao
gradC1 = gradient(c1 , [w1 w2 w3]);

%verificar as condiçóes de optimalidade

%calcular tringulo invertido de w de L
% ou (acho)
%calcular a matriz hessiana de L em ordem a w
gradl = gradient(L, [w1 w2 w3 y1]);

vec = [0,0,0,0];
[ws1 ws2 ws3 ys1] = solve(gradl == vec);


%Calular a matriz hessiana de L em w ordem a w
hessiLw = hessian(L,[w1 w2 w3]);

 %espacicio nucleos dos gradientes das restições em w*
 z = null(gradC1')

 % 2 and
%2 condi
hessLw_opt= subs(hessLw,[w1 w2 w3 l1], [w_opt(1) w_opt(2) w_opt(3) 3])
Z' * hessLw * Z