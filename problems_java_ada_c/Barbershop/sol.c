int8 n = 4;
customers = 0;
mutex = Semaphore(1);
customer = Semaphore(0);
barber = Semaphore(0);
customerDone = Semaphore(0);
barberDone = Semaphore(0);

barber() {
    while(1){
        customer.wait();
        barber.signal();

        cutHair();
        
        customerDone.wait();
        barberDone.signal();
        
        barber.signal();
    }
}

customer(){
    while(1){
        mutex.wait()
        if(customers == n) {
            mutex.signal()
            balk();
        }             
        customers +=1;
        mutex.signal();
        
        customer.signal();
        barber.wait();
       
        getHairCut();

        customerDone.signal();
        barberDone.wait();

        mutex.wait();
            customers -=1;
        mutex.signal();
    }
}

// Fifo solution Queue. Barber needs mutex
