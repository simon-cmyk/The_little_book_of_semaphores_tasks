# class Barrier :
# 2 def __init__ ( self , n ):
# 3 self . n = n
# 4 self . count = 0
# 5 self . mutex = Semaphore (1)
# 6 self . turnstile = Semaphore (0)
# 7 self . turnstile2 = Semaphore (0)
# 8
# 9 def phase1 ( self ):
# 10 self . mutex . wait ()
# 11 self . count += 1
# 12 if self . count == self . n :
# 13 self . turnstile . signal ( self . n )
# 14 self . mutex . signal ()
# 15 self . turnstile . wait ()
# 16
# 17 def phase2 ( self ):
# 18 self . mutex . wait ()
# 19 self . count -= 1
# 20 if self . count == 0:
# 21 self . turnstile2 . signal ( self . n )
# 22 self . mutex . signal ()
# 23 self . turnstile2 . wait ()
# 24
# 25 def wait ( self ):
# 26 self . phase1 ()
# 27 self . phase2 ()

# barrier = Barrier ( n ) # initialize a new barrier
# 2 barrier . wait () # wait at a barrier