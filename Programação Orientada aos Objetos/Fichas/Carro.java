public class Carro{
    private String marca;
    private String modelo;
    private int ano;
    private double consumoporkm;
    private double kmtotais;
    private double mediaconsumoinicio;
    private double kmultimoper;
    private double mediaconsumoultimoper;
    private double recuperaenergia;
    private boolean ligado;

    public Carro(){
        this.marca = new String(); // "n/a"
        this.modelo = new String();
        this.ano = 0;
        this.consumoporkm = 0;
        this.kmtotais = 0;
        this.mediaconsumoinicio = 0;
        this.mediaconsumoultimoper = 0;
        this.kmultimoper = 0;
        this.recuperaenergia = 0;
        this.ligado = false;
    }

    public String getModelo(){
        return this.modelo;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public String getMarca(){
        return this.marca;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public int getAno(){
        return this.ano;
    }

    public void setAno(int ano){
        this.ano = ano;
    }

    public double getConsumoporkm(){
        return this.consumoporkm;
    }

    public void setConsumoporkm(double consumoporkm){
        this.consumoporkm = consumoporkm;
    }

    public double getKmtotais(){
        return this.kmtotais;
    }

    public void setKmtotais(double kmtotais){
        this.kmtotais = kmtotais;
    }

    public double getMediaconsumoinicio(){
        return this.mediaconsumoinicio;
    }

    public void setMediaconsumoinicio(double mediaconsumoinicio){
        this.mediaconsumoinicio = mediaconsumoinicio;
    }

    public double getMediaconsumoultimoper(){
        return this.mediaconsumoultimoper;
    }

    public void setMediaconsumoultimoper(double mediaconsumoultimoper){
        this.mediaconsumoultimoper = mediaconsumoultimoper;
    }
    public void setMediaconsumo(double mediaconsumoultimoper){
        this.mediaconsumoultimoper = mediaconsumoultimoper;
    }

    public double getKmultimoper(){
        return this.kmultimoper;
    }

    public void setKmultimoper(double kmultimoper){
        this.kmultimoper = kmultimoper;
    }

    public double getRecuperaenergia(){
        return this.recuperaenergia;
    }

    public void setRecuperaenergia(double recuperaenergia){
        this.recuperaenergia = recuperaenergia;
    }

    public boolean getLigado(){
        return this.ligado;
    }

    public void setLigado(boolean ligado){
        this.ligado = ligado;
    }

    public Carro(String marca, String modelo, int ano, double consumoporkm, double kmtotais, double mediaconsumoinicio, double kmultimoper,double mediaconsumoultimoper, double recuperaenergia, boolean ligado){
        this.setMarca(marca);
        this.setModelo(modelo);
        this.setAno(ano);
        this.setConsumoporkm(consumoporkm);
        this.setKmtotais(kmtotais);
        this.setMediaconsumoinicio(mediaconsumoinicio);
        this.setKmultimoper(kmultimoper);
        this.setMediaconsumoultimoper(mediaconsumoultimoper);
        this.setRecuperaenergia(recuperaenergia);
        this.setLigado(ligado);
    }

    public boolean equals(Object o){
        if (o == this){
            return true;
        }
        if(o == null || this.getClass() != o.getClass()){
            return false;
        }
        Carro s = (Carro) o;
        return this.getMarca().equals(s.getMarca()) && this.getModelo().equals(s.getModelo()) && this.getAno() == s.getAno() && this.getConsumoporkm() == s.getConsumoporkm()
        && this.getKmtotais() == s.getKmtotais() && this.getMediaconsumoinicio() == s.getMediaconsumoinicio() && this.getKmultimoper() == s.getKmultimoper() 
        && this.getMediaconsumoultimoper() == s.getMediaconsumoultimoper() && this.getRecuperaenergia() == s.getRecuperaenergia();
    }

    public void ligaCarro(){
        if(!ligado){
            this.setLigado(true);
            this.setKmultimoper(0);
        }
    }

    public void desligaCarro(){
        if(ligado){
            this.setLigado(false);
        }
    }

    public void resetUltimaViagem(){
        this.setKmultimoper(0);
    }

    public void avancaCarro(double metros, double velocidade){
        ligaCarro();
        resetUltimaViagem(); 
        double km = metros / 1000; 
        this.setKmultimoper(km); 
        this.setKmtotais(this.getKmtotais() + km); 
        double consumov = km * consumoporkm; 
        this.setMediaconsumoultimoper(consumov / km); 
        double consumoTotal = (this.mediaconsumoinicio * (this.getKmtotais() - km)) + consumov;
        this.setMediaconsumoinicio(consumoTotal / this.getKmtotais());
    }

    public void travaCarro(double metros){
        double km = metros / 1000; 
        this.setKmultimoper(this.getKmultimoper() + km); 
        this.setKmtotais(this.getKmtotais() + km);
        double energiareg = km * recuperaenergia; 
        double consumo = (km * consumoporkm) - energiareg; 
        this.setMediaconsumoultimoper(consumo / km); 
        double consumoTotal = (this.mediaconsumoinicio * (this.getKmtotais() - km)) + consumo;
        this.setMediaconsumoinicio(consumoTotal / this.getKmtotais()); 
    }

    public String toString(){
        return this.getMarca() + " " + this.getModelo() + " com : " + this.getKmtotais() +" km " + "\n" + "no ultimo percurso percorreu: " + this.getKmultimoper() + " km" + " teve uma media de consumo no utlimo percurso de: " + this.getMediaconsumoultimoper();
    }

    public Carro(Carro outro){
        this(outro.getMarca() , outro.getModelo(), outro.getAno(), outro.getConsumoporkm(), outro.getKmtotais(), outro.getMediaconsumoinicio(), outro.getKmultimoper(),outro.getMediaconsumoultimoper(), outro.getRecuperaenergia(), outro.getLigado());
    }

    public Carro clone(){
        return new Carro(this);
    }
}   