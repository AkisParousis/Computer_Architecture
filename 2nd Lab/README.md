### ΑΡΧΙΤΕΚΤΟΝΙΚΗ ΥΠΟΛΟΓΙΣΤΩΝ

#### **ΠΑΡΟΥΣΗΣ ΣΤΑΥΡΟΣ ΔΗΜΟΣ 8892 / ΠΟΥΝΙΩΤΗΣ ΣΤΑΥΡΟΣ 8995**  
##### **Εργαστήριο Β / Ομάδα 17**



#### **2η Εργαστηριακή Άσκηση**

##### Βήμα 1ο
###### 1ο Ερώτημα

Αρχικά, για την κατασκευή του simulation χρησιμοποιήσαμε στο terminal τις παρακάτω εντολές:

>./build/ARM/gem5.opt -d spec_results/specbzip configs/example/se.py --cputype=MinorCPU --caches --l2cache -c spec_cpu2006/401.bzip2/src/specbzip -o
>"spec_cpu2006/401.bzip2/data/input.program 10" -I 100000000

>./build/ARM/gem5.opt -d spec_results/specmcf configs/example/se.py --cputype=MinorCPU --caches --l2cache -c spec_cpu2006/429.mcf/src/specmcf -o
>"spec_cpu2006/429.mcf/data/inp.in" -I 100000000

>./build/ARM/gem5.opt -d spec_results/spechmmer configs/example/se.py --cputype=MinorCPU --caches --l2cache -c spec_cpu2006/456.hmmer/src/spechmmer -o "--
>fixed 0 --mean 325 --num 45000 --sd 200 --seed 0
>spec_cpu2006/456.hmmer/data/bombesin.hmm" -I 100000000

>./build/ARM/gem5.opt -d spec_results/specsjeng configs/example/se.py --cputype=MinorCPU --caches --l2cache -c spec_cpu2006/458.sjeng/src/specsjeng -o
>"spec_cpu2006/458.sjeng/data/test.txt" -I 100000000

>./build/ARM/gem5.opt -d spec_results/speclibm configs/example/se.py --cputype=MinorCPU --caches --l2cache -c spec_cpu2006/470.lbm/src/speclibm -o "20
>spec_cpu2006/470.lbm/data/lbm.in 0 1
>spec_cpu2006/470.lbm/data/100_100_130_cf_a.of" -I 100000000

Από τα αρχεία ***config.ini*** του φακέλου ***spec_results*** για κάθε ένα από τα ***specbzip***, ***spechmmer***, ***speclibm***, ***specmcf***, ***specsjeng*** παρατηρούμε τα εξής μεγέθη:

*Cache_line_size*

~~~python
11 [system]
.
.
15 cache_line_size=64
~~~

*icache_size* & *associativity*

~~~python
812 [system.cpu.icache]
.
.
816 assoc=2
.
.
833 size=32768
~~~

*dcache_size* & *associativity*

~~~python
148 [system.cpu.dcache]
.
.
152 assoc=2
.
.
169 size=65536
~~~

*l2_cache_size* & *associativity*

~~~python
1057 [system.l2]
.
.
1061 assoc=8
.
.
1078 size=2097152
~~~

<pre>Τα μεγέθη είναι ίδια για όλα τα benchmark</pre>


###### 2ο Ερώτημα

Από τα αρχεία ***stats.txt*** του φακέλου ***spec_results*** για κάθε ένα από τα ***specbzip***, ***spechmmer***, ***speclibm***, ***specmcf***, ***specsjeng*** παρατηρούμε τα παρακάτω αποτελέσματα:

**specbzip**

~~~
sim_seconds                                  0.083847                       # Number of seconds simulated

system.cpu.cpi                               1.676947                       # CPI: cycles per instruction

system.cpu.icache.overall_miss_rate::total     0.000075                       # miss rate for overall accesses

system.cpu.dcache.overall_miss_rate::total     0.014289                       # miss rate for overall accesses

system.l2.overall_miss_rate::total           0.294749                       # miss rate for overall accesses
~~~

**spechmmer**

~~~
sim_seconds                                  0.059410                       # Number of seconds simulated

system.cpu.cpi                               1.188197                       # CPI: cycles per instruction

system.cpu.icache.overall_miss_rate::total     0.000204                       # miss rate for overall accesses

system.cpu.dcache.overall_miss_rate::total     0.001692                       # miss rate for overall accesses

system.l2.overall_miss_rate::total           0.079948                       # miss rate for overall accesses
~~~

**speclibm**

~~~
sim_seconds                                  0.174779                       # Number of seconds simulated

system.cpu.cpi                               3.495573                       # CPI: cycles per instruction

system.cpu.icache.overall_miss_rate::total     0.000098                       # miss rate for overall accesses

system.cpu.dcache.overall_miss_rate::total     0.060972                       # miss rate for overall accesses

system.l2.overall_miss_rate::total           0.999927                       # miss rate for overall accesses
~~~

**specmcf**

~~~
sim_seconds                                  0.055471                       # Number of seconds simulated

system.cpu.cpi                               1.109419                       # CPI: cycles per instruction

system.cpu.icache.overall_miss_rate::total     0.000037                       # miss rate for overall accesses

system.cpu.dcache.overall_miss_rate::total     0.002038                       # miss rate for overall accesses

system.l2.overall_miss_rate::total           0.727788                       # miss rate for overall accesses
~~~

**specsjeng**

~~~
sim_seconds                                  0.513819                       # Number of seconds simulated

system.cpu.cpi                               10.276385                       # CPI: cycles per instruction

system.cpu.icache.overall_miss_rate::total     0.000020                       # miss rate for overall accesses

system.cpu.dcache.overall_miss_rate::total     0.121831                       # miss rate for overall accesses

system.l2.overall_miss_rate::total           0.999978                       # miss rate for overall accesses
~~~

<pre>Τα γραφήματα βρίσκονται στον φάκελο Graphs στο αρχείο <a href="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/Step1_Q2_graph.md" target="_blank">Step1_Q2_graph.md</a></pre>

Ένας γενικός κανόνας που παρατηρούμε είναι πως όσο μεγαλύτερα τα miss rate ενός spec, τόσο μεγαλύτερο και το cpi του. Αυτό με τη σειρά του οδηγεί σε μεγαλύτερη διάρκεια εξομοίωσης, γεγονός πολύ λογικό.


###### 3ο Ερώτημα

Όντως στο αρχείο ***stats.txt*** μπορούμε να βρούμε τις παρακάτω πληροφορίες για το ρολόι:

~~~python
154 system.clk_domain.clock                          1000                       # Clock period in ticks
754 system.cpu_clk_domain.clock                       500                       # Clock period in ticks
~~~

Το system domain clock ή αλλιώς uncore frequency χρονίζει διάφορα μέρη του συστήματος (non-core CPU parts), όπως memory controller, memory bus, DVFS (Dynamic voltage and frequency scaling) handler ενώ το cpu domain clock χρονίζει τα μέρη του επεξεργαστή που εμπλέκονται στο να εκτελέσουν εντολές, όπως  ALU, FPU, L1 instruction and data cache and L2 cache.

Αν προσθέσουμε ακόμα έναν επεξεργαστή το ρολόι του θα είναι το cpu clock.

Τέλος όσον αφορά το scaling, πράγματι στις μικρές συχνότητες με τις οποίες ασχολούμαστε υπάρχει τέλειο scaling. Δηλαδή ο υποδιπλασιασμός του cpu clock, οδήγησε σε διπλασιασμό του χρόνου εξομοίωσης. Λογικά, όσο αυξάνουμε τη συχνότητα του επεξεργαστή θα "χαλάει" το scaling, διότι ο επεξεργαστής είναι συνήθως αρκετά πιο γρήγορος απο τα υπόλοιπα στοιχεία του συστήματος, οπότε θα αναγκαστεί να περιμένει.


##### Βήμα 2ο
###### 1ο Ερώτημα

**specbzip**

Για το specbzip αποφασίσαμε ότι το *icache miss rate* βρίσκεται ήδη σε βαθμό που δε δέχεται διακριτές βελτιώσεις, οπότε το αφήσαμε αμετάβλητο.

**spechmmer**

Το cpi του spechmmer ήταν ήδη κοντά στην μονάδα, οπότε υποθέσαμε με κάποιες μικρές αλλαγές κυρίως στην l2_cache και l1_dcache που έχουν τα υψηλότερα miss rate θα βελτιωθεί το cpi.

**speclibm**

Όμοια με τα παραπάνω στόχος ήταν να ρίξουμε το miss rate κυρίως της *l2_cache* και κατά δεύτερον της *l1_dcache*. Το *icache miss rate* βρίσκεται ήδη σε ικανοποιητικό βαθμό.

**specmcf**

Στο συγκεκριμένο benchmark έχουμε μεγαλύτερο icache miss rate οπότε δε θα αγνοήσουμε κάποιο παράγοντα και μέσω παρατηρήσεων θα καταλήξουμε σε κάποιο βέλτιστο build. Παρ'ολ'αυτά επειδή το cpi είναι αρκετά κοντά στη μονάδα ίσως δε χρειαστεί να μεταβληθούν όλοι οι παράγοντες.

**specsjeng**

Παρόμοια με το libm το cpi είναι πιθανότερο να μειωθεί μεταβάλλοντας κυρίως το *cache_line_size*, το *l2_cache_size* και το *l1_dcache_size*.

###### 2ο Ερώτημα

Για όλα τα benchmark συγκρίναμε πρώτα τα χαρακτηριστικά μεμονωμένα και στη συνέχεια με βάση τα αποτελέσματα φτιάξαμε κάποια βελτιστοποιημένα build.

**specbzip**

*cache_line_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specbzip_cachelinesize.png?raw=true">

*dcache_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specbzip_dcachesize.png?raw=true">

*dcache_assoc*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specbzip_dcacheassoc.png?raw=true">

*l2_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specbzip_l2size.png?raw=true">

*l2_assoc*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specbzip_l2assoc.png?raw=true">

Optimal Build1: all default except l2cache_size = 4MB & l1dcache_size = 128kB & l1dcache_assoc = 4

Optimal Build2: all default except l2cache_size = 4MB & & l2cache_assoc = 4 & l1dcache_size = 128kB & l1dcache_assoc = 8 & cacheline_size = 256

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specbzip_opt.png?raw=true">


**spechmmer**

*cache_line_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/spechmmer_cachelinesize.png?raw=true">

*dcache_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/spechmmer_dcachesize.png?raw=true">

*dcache_assoc*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/spechmmer_dcacheassoc.png?raw=true">

*l2_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/spechmmer_l2size.png?raw=true">

Optimal Build1: all default except l2cache_size = 1MB & l1dcache_size = 128kB & l1dcache_assoc = 4 & cacheline_size = 256KB

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/spechmmer_opt.png?raw=true">


**speclibm**

*cache_line_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/speclibm_cachelinesize.png?raw=true">


**specmcf**

*cache_line_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specmcf_datacacheline.png?raw=true">

**specsjeng**

*cache_line_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/2nd%20Lab/Graphs/specjeng_cachelinesize.png?raw=true">


##### Βήμα 3ο
###### Ερώτημα

Η συνάρτηση κόστους που θεωρήσαμε είναι η εξής :

x1/16KB + x2/256KB + assocl1 + assocl2 / 2 + c/8B

* x1 : άθροισμα μεγεθών icache + dcache
* x2 : μέγεθος l2cache
* assoc 1 : αθροισμα icache_assoc + dcache_assoc
* assoc 2 : l2cache_assoc
* c : cache_line_size


Γνωρίζουμε ότι σε σημερινές αρχιτεκτονικές χρησιμοποιούνται l1cache της τάξης μεγέθους 32-64KB per core και l2cache της τάξης μεγέθους 256-512KB per core. Η μεταξύ τους αναλογία ισούται με 8. Γνωρίζοντας όμως ότι η l1cache είναι πιο "ακριβή" σε θέμα κατασκευής και φυσικού χώρου αυξήσαμε την μεταξύ τους αναλογία σε 16.

Επίσης η cache line κοστίζει παραπάνω όσο αυξάνει το μέγεθος της. Αυτό οφείλεται στο γεγονός ότι μεγαλύτερο μέγεθος οδηγεί στην αποθήκευση περισσότερων λέξεων στο ίδιο block/line , άρα και περισσότερες συγκρίσεις προκειμένου να βρεθεί το ζητούμενο.

Τέλος, στη συνάρτηση κόστους όσο μεγαλύτερο associativity έχουμε προστίθεται μεγαλύτερη ποινή , διότι όσο αυξάνεται το associativity έχουμε αρνητική επίδραση στην περιπλοκότητα και στο χρόνο προσπέλασης. Για παράδειγμα αν έχουμε ίδιες αποδόσεις για L1I: 64kB 2-way και L1I: 64kB 4-way θα προτιμήσουμε τη πρώτη.
