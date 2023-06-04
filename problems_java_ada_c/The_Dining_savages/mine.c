servings = 0;
mutex = Semaphore(1);
emptyPot = Semaphore(0);
fullPot = Semaphore(0);


cook() {
    while(1) {
        emptyPot.wait();
        putServings(N=5);
        mutex.wait();
             servings = N;
        mutex.signal();
        fullPot.signal();
    }
}

savage() {
    while(1) {
        mutex.wait();
        if(servings == 0) {
            mutex.signal();
            emptyPot.signal();
            fullPot.wait();
        } else {
            getServing();
            servings--;
            mutex.signal();
            eat();
        }
    }
}

// Solutions:
cook: 
while True:
    emptyPot.wait()
    putServings(N=5)
    fullPot.signal()
// Scoreboard but don't need mutex for cook
savage:
while True:
    mutex.wait()
        if servings == 0:
            emptyPot.signal()
            fullPot.wait()
            servings = N
        servings -= 1
        getServingsFromPot()
    mutex.signal()

    eat()