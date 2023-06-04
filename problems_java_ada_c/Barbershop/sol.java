class Barbershop(){
    private int customers = 0;
    private boolean busy = False;
    private boolean customerDone = False;
    
    synchronized customer(){
        if(customers == 4) {
            balk()
        }
        customers += 1;
        notifyAll();

        while(busy) wait();
        busy = True;
        getHairCut();
        customerDone = True;
        notifyAll();
    } 

    synchronized barber(){
        while(1){
            busy = False
            notifyAll();
            while(customers == 0) wait();
            serveHairCut();
            while(customerDone==False) wait();
            customerDone = False;
        }
    }
}