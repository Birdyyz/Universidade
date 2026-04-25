-module(jogo).
-export(create/0, participa/1, adivinha/2).

create()->
    spawn(fun() -> jogo([])end).

participa(Jogo)->
    Jogo ! {participa, self()},
    receive
        {participa, Jogo} ->
            Partida end.

adivinha(Partida,N) ->
    Partida ! {adivinha,N, self()},
    receive
        {result,Res} ->
            Res end.

jogo(Jogadores) when length(Jogadores) =:4 ->
    Partida = spawn(fun() partida(...) end),
    [Jogador ! {partida, Partida} || Jogador <- Jogadores],
    spawn(fun() -> receive after 60000 end, Partida ! timeout end),
    jogo([]).

jogo(Jogadores) ->
    receive
        {participa, Jogador} ->
            jogo([Jogador | Jogadores])
    end.