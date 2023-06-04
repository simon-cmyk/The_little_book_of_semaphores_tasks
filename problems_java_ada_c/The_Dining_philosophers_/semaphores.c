/*
• Only one philosopher can hold a fork at a time.
• It must be impossible for a deadlock to occur.
• It must be impossible for a philosopher to starve waiting for a fork.
• It must be possible for more than one philosopher to eat at the same time
*/
#define PHILOSOPHERCOUNT 5

fork[PHILOSOPHERCOUNT] = 
{
    Semaphore(1),
    Semaphore(1),
    Semaphore(1),
    Semaphore(1),
    Semaphore(1),
    };

int left(i) {
    return i;
}

int right(i) {
    return (i + 1) % (PHILOSOPHERCOUNT);
}



void get_forks() {
    fork[right(i)].wait();
    fork[left(i)].wait();
}

void put_forks() {
    fork[right(i)].signal();
    fork[left(i)].signal();
}

philosopher() {
    while(1) {
       think();
       get_forks();
       eat();
       put_forks();
    }
}

// Solution 1 -> Keep the number to n-1
footman = Semaphore(PHILOSOPHERCOUNT - 1);


void get_forks(i) {
    footman.wait();
    fork[right(i)].wait();
    fork[left(i)].wait();
}

void put_forks(i) {
    fork[right(i)].signal();
    fork[left(i)].signal();
    footman.signal();
}

// Solution 2 -> If philosopher0 is leftie. 
// if there are at least one leftie and one rightie -> deadlock not possible
// proof by contradiction

// Tanenbaums solution is not starvation free. find a repeating pattern
