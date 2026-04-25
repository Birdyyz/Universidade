import java.util.Random;

interface Jogo { 
    Partida participa(); 
} 
interface Partida { 
    String adivinha(int n); 
}

class JogoImpl implements Jogo { 
    PartidaImpl partida = new PartidaImpl();
    public synchronized Partida participa(){ 
        PartidaImpl minhaPartida = partida;
        partida.jogadores += 1;
         if (partida.jogadores == 4){
            partida = new PartidaImpl();
            notifyAll();
         }
         else{
            while(partida == minhaPartida){ // o teste podia ser feito com jogadores pq os jogadores tao dentro da partida
                wait();
            }
         }
         return minhaPartida;
    } 
}

class PartidaImpl implements Partida{
    int n;
    int tentativas = 100;
    int jogadores = 0;
    boolean ganhou = false;
    Random rand = new Random();
    int numero = rand.nextInt(100) + 1; 
    boolean timeout = false;

    synchronized void timeout(){
        timeout = true;
    }
    void start(){
        new Thread() -> {
            try{
                Thread.sleep(60000);
            } catch (InterruptedException ignored) {}
            timeout();
        }.start();
    }

    public synchronized String adivinha(int n) { 
        this.n = n;
        if (ganhou){
            return "PERDEU";
        }
        else if(timeout){
            return "TEMPO";
        }
        else if(tentativas <= 0){
            ganhou = true;
            return "PERDEU";
        }
        else if (this.n == numero){
            ganhou = true;
            return "GANHOU";
        }
        else if (this.n < numero){  
            return "MAIOR";
        }
        else{
            return "MENOR";
        }

    }
}