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

Τέλος όσον αφορά το scaling, πράγματι για τα *specbzip*, *spechmmer* και *specmcf* υπάρχει τέλειο scaling. Δηλαδή ο υποδιπλασιασμός του cpu clock, οδήγησε σε διπλασιασμό του χρόνου εξομοίωσης. Όμως για τα speclibm , specsjeng δεν έχουμε τέλειο scaling, γεγονός που μάλλον οφείλεται στη δυσκολία των caches και της μνήμης να λάβουν τα missed data και instructions σε διπλάσιο ρυθμό.

<table>
<thead>
<tr>
<th></th>
<th>specbzip</th>
<th>spechmmer</th>
<th>speclibm</th>
<th>specmcf</th>
<th>specsjeng</th>
</tr>
</thead>
<tbody>
<tr>
<td>1 GHz</td>
<td>160.7</td>
<td>118.5</td>
<td>262.24</td>
<td>109.23</td>
<td>705.4</td>
</tr>
<tr>
<td>2 GHz</td>
<td>83.8</td>
<td>59.4</td>
<td>174.77</td>
<td>55.4</td>
<td>513.81</td>
</tr>
</tbody>
</table>


##### Βήμα 2ο
###### 1ο Ερώτημα

Για όλα τα benchmarks με εξαίρεση το *specmcf* παρατηρούμε ότι το icache miss rate είναι ήδη σε ικανοποιητικό βαθμό , οπότε τυχόν αλλαγές της icache δε θα προσφέρουν κάποια διακριτή αλλαγή.

###### 2ο Ερώτημα

Για διάφορα μεγέθη των χαρακτηριστικών της αρχιτεκτονικής σχεδίασης, αθροίσαμε τα cpi των benchmark και υπολογίσαμε το μέσο cpi.

Για τους υπολογισμούς των παραπάνω έγιναν περίπου 100 simulations αλλάζοντας στο κάθε ένα απο αυτά το μέγεθος ενός χαρακτηριστικού μέσω του [longScript.sh](https://github.com/AkisParousis/Computer_Architecture/tree/main/2nd%20Lab/Scripts)


*cache_line_size*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/Cache_line_size.png">


*icache_size*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/icache_size.png">


*icache_assoc*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/icache_assoc.png">


*dcache_size*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/dcache_size.png">


*dcache_assoc*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/dcache_assoc.png">


*l2_size*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/l2cache_size.png">

~~~
Έχει γίνει λάθος στα μεγέθη του οριζόντιου άξονα. Τα πραγματικά είναι 512kB, 1MB, 2MB, 4MB 
~~~


*l2_assoc*

<img src="https://raw.githubusercontent.com/AkisParousis/Computer_Architecture/main/2nd%20Lab/Graphs/Step2_Q2_graphs/l2cache_assoc.png">




##### Βήμα 3ο
###### Ερώτημα

Η συνάρτηση κόστους που κατασκευάσαμε εξαρτάται από την επίδραση των χαρακτηριστικών της αρχιτεκτονικής σχεδίασης, στο average cpi των benchmark συναρτήσει τους κόστους μεταβολής του μεγέθους. Για παράδειγμα, μπορεί να παρατηρούμε ότι το cache_line_size των 256Β προσφέρει ένα χαμηλότερο average cpi από αυτό των 128Β, παρ'όλ'αυτά η διαφορά των cpi δεν δικαιολογεί τη διαφορά κόστους. Παρακάτω εξηγούμε πως επιδρά κάθε χαρακτηριστικό στο κόστος.

*cache_line_size*

Η cache line κοστίζει παραπάνω όσο αυξάνει το μέγεθος της. Αυτό οφείλεται στο γεγονός ότι μεγαλύτερο μέγεθος οδηγεί στην μείωση των γραμμών που με τη σειρά του μπορεί να αυξήσει τα conflict misses. Επίσης , αν και σε μικρό βαθμό , αυξάνεται το transfer time. Όμως από τις δοκιμές που διεξάγαμε παρατηρήσαμε ότι το cache line size έπαιζε τον επιδραστικότερο ρόλο στο average cpi.

[Source](https://stackoverflow.com/questions/55647071/does-cacheline-size-affect-memory-access-latency)

*cache_size*

Γνωρίζουμε αλλά και παρατηρούμε απο τις δοκιμές μας ότι όσο και να αυξήσουμε το μέγεθος των cache μετά από ένα σημείο, το hit rate τους παραμένει σταθερό. Επομένως η αύξηση του μεγέθους τους οδηγά και σε αύξηση του κόστους.
Επιπλέον γνωρίζουμε ότι η l1cache είναι πιο "ακριβή" σε θέμα κατασκευής και φυσικού χώρου οπότε τυχόν αύξηση του μεγέθους της έχει μεγαλύτερο κόστος από τυχόν αύξηση του μεγέθους της l2.

[Source_1](https://www.extremetech.com/extreme/188776-how-l1-and-l2-cpu-caches-work-and-why-theyre-an-essential-part-of-modern-chips)
[Source_2](https://www.techspot.com/article/2066-cpu-l1-l2-l3-cache/)

*associativity*

Τέλος, στη συνάρτηση κόστους όσο μεγαλύτερο associativity έχουμε αύξανεται σε ένα βαθμό , διότι όσο αυξάνεται το associativity έχουμε αρνητική επίδραση στην περιπλοκότητα και στο χρόνο προσπέλασης. Για παράδειγμα αν έχουμε ίδιες αποδόσεις για L1I: 64kB 2-way και L1I: 64kB 4-way θα προτιμήσουμε τη πρώτη περίπτωση.

[Source](https://www.sciencedirect.com/topics/computer-science/set-associativity)

Με βάση όλα τα παραπάνω καταλήξαμε στην παρακάτω συνάρτηση κόστους :


(1/1.1)*(x1/32kB) + (1/1.5)*(x2/256kB) + (1/1.05)*(assoc_1 / 2) + (1/1.05) * (assoc_2 / 4) + (c/16B) * (1/2.2)

* x1 : άθροισμα μεγεθών icache + dcache
* x2 : μέγεθος l2cache
* assoc_1 : αθροισμα icache_assoc + dcache_assoc
* assoc_2 : l2cache_assoc
* c : cache_line_size

~~~
Οι συντελεστές και οι διαιρέτες επιλέχθηκαν με τέτοιο τρόπο ωστέ να κανονικοποιηθούν τα μεγέθη και να να μπορούν να συγκριθούν ως προς την επίδραση τους στο κόστος.
~~~


Στη συνέχεια επιλέξαμε 9 build που θεωρήσαμε οτι θα μπορούσαν να αποτελούν βέλτιστα προκειμένου να συγκρίνουμε τα score τους. Τα score βγαίνουν από τη συνάρτηση κόστους πολλαπλασιασμένη με το cpi του build.
Τα cpi έχουν υπολογιστεί από τα simulations που κάναμε και τα αποτελέσματα βρίσκονται στον φάκελο [Results](https://github.com/AkisParousis/Computer_Architecture/tree/main/2nd%20Lab/Results)


**specbzip**
<table>
<thead>
<tr>
<th>specbzip</th>
<th>Score</th>
</tr>
</thead>
<tbody>
<tr>
<td>Default</td>
<td>22.87</td>
</tr>
<tr>
<td>L1D: 128kB 2-way</td>
<td>25.45</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>24.33</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>24.38</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>24.46</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>31.28</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>21.27</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>25.66</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>31.51</td>
</tr>
</tbody>
</table>

**spechmmer**
<table>
<thead>
<tr>
<th>spechmmer</th>
<th>Score</th>
</tr>
</thead>
<tbody>
<tr>
<td>Default</td>
<td>16.26</td>
</tr>
<tr>
<td>L1D: 128kB 2-way</td>
<td>18.39</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>17.38</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>17.32</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>17.38</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>15.12</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>13.09</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>18.32</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>22.62</td>
</tr>
</tbody>
</table>

**specmcf**
<table>
<thead>
<tr>
<th>specmcf</th>
<th>Score</th>
</tr>
</thead>
<tbody>
<tr>
<td>Default</td>
<td>17.17</td>
</tr>
<tr>
<td>L1D: 128kB 2-way</td>
<td>19.43</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>18.35</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>16.75</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>16.82</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td></td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td></td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td></td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td></td>
</tr>
</tbody>
</table>

**speclibm**
<table>
<thead>
<tr>
<th>speclibm</th>
<th>Score</th>
</tr>
</thead>
<tbody>
<tr>
<td>Default</td>
<td>47.64</td>
</tr>
<tr>
<td>L1D: 128kB 2-way</td>
<td>53.97</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>50.95</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>50.77</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>50.96</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td></td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td></td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>38.77</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>37.39</td>
</tr>
</tbody>
</table>

**specsjeng**
<table>
<thead>
<tr>
<th>specsjeng</th>
<th>Score</th>
</tr>
</thead>
<tbody>
<tr>
<td>Default</td>
<td>138.44</td>
</tr>
<tr>
<td>L1D: 128kB 2-way</td>
<td>156.83</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>148.07</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>147.52</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>148.06</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>192.31</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>128.79</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>104.14</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>93.55</td>
</tr>
</tbody>
</table>


#### Κριτική

Η εργασία χρειάστηκε αισθητά περισσότερη προσπάθεια από την πρώτη,  οι μεγαλύτερες προκλήσεις που αντιμετωπίσαμε ήταν η διαχείριση του χρόνου αλλά και η επεξεργασία του μεγάλου όγκου δεδομένων που συγκεντρώθηκαν από το πλήθος των δοκιμών. Η εργασία μας βοήθησε να κατανοήσουμε καλύτερα τα επίπεδα μνήμης του επεξεργαστή αλλά και να δούμε από πρώτο χέρι πως γίνεται το benchmarking με το οποίο διόλου λίγες φορές έχουμε ασχοληθεί κάνοντας έρευνα αγοράς για τα διάφορα parts του προσωπικού μας υπολογιστή. Το πιο σημαντικό όμως είναι ότι ήρθαμε σε πρώτη επαφή με τη διαδικασία σχεδίασης και αξιολόγησης διάφορων αρχιτεκτονικών και θεωρούμε πως πήραμε μια γεύση για το πως λειτουργούν οι επαγγελματίες σχεδιαστές. 
