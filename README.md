### ΑΡΧΙΤΕΚΤΟΝΙΚΗ ΥΠΟΛΟΓΙΣΤΩΝ

#### **ΠΑΡΟΥΣΗΣ ΣΤΑΥΡΟΣ ΔΗΜΟΣ 8892 / ΠΟΥΝΙΩΤΗΣ ΣΤΑΥΡΟΣ 8995**
##### **Εργαστήριο Β / Ομάδα 17**

#### **1η Εργαστηριακή Άσκηση**


###### 1ο Ερώτημα

Αρχικά, από την εντολή που χρησιμοποιήσαμε στο terminal για την κατασκευή του simulation, γνωρίζουμε για τον τύπο του επεξεργαστή :

> ./build/ARM/gem5.opt -d hello_resultconfigs/example/arm/starter_se.py--**cpu="minor"** "tests/test-progs/hello/bin/arm/linux/hello"

* *cpu_type* - Minor  

Από τη συνάρτηση ***main*** του ***starter_se.py*** μπορούμε να αναγνωρίσουμε τα παρακάτω βασικά χαρακτηριστικά : 

1. *cpu_frequency* - 4Ghz

   > parser.add_argument("--cpu-freq", type=str, default="4GHz")

2. *number_of_cores* - 1

   > parser.add_argument("--num-cores", type=int, default=1,
   >                         help="Number of CPU cores")

3. *memory_type* - DR3_1600_8x8

   > parser.add_argument("--mem-type", default="DDR3_1600_8x8",
   >                         choices=ObjectList.mem_list.get_names(),
   >                         help = "type of memory to use")

4. _memory_channels_ - 2

   > parser.add_argument("--mem-channels", type=int, default=2,
   >                         help = "number of memory channels")

5. *memory_size* - 2GB

   > parser.add_argument("--mem-size", action="store", type=str,
   >                         default="2GB",
   >                         help="Specify the physical memory size")

Επίσης από τη συνάρτηση *__init__* της κλάσης ***SimpleSeSystem*** συμπεραίνουμε ότι το σύστημα μας έχει 

* *δύο cache lines* μεγέθους γραμμής 64 Bytes

  > if self.cpu_cluster.memoryMode() == "timing":
  >       self.cpu_cluster.addL1()
  >       self.cpu_cluster.addL2(self.cpu_cluster.clk_domain)

  > cache_line_size = 64

* *Voltage_Domain* - 3.3V

  > self.voltage_domain = VoltageDomain(voltage="3.3V")

* *Clock_Domain* - 1GHz

  > self.clk_domain = SrcClockDomain(clock="1GHz",
  >                                          voltage_domain=self.voltage_domain)





###### 2ο Ερώτημα

###### a)

Στο αρχείο ***config.ini*** μπορούμε να επαληθεύσουμε τα εξής χαρακτηριστικά :

*Cache_size* & *Memory_size* & *Memory_channels*

~~~python
11 [system]
.
.
15 cache_line_size=64
.
.
21 mem_ranges=0:2147483648
22 memories=system.mem_ctrls0.dram system.mem_ctrls1.dram
~~~



*Clock_Domain* :

```python
42 [system.clk_domain]
43 type=SrcClockDomain
44 clock=1000
```
*Cpu_frequency* :

~~~python
56 [system.cpu_cluster.clk_domain]
57 type=SrcClockDomain
58 clock=250 #250ns => F = 4GHz
~~~

*Cpu_type* :

~~~python
64 [system.cpu_cluster.cpus]
65 type=MinorCPU
~~~

*Voltage_Domain* :

```python
1649 [system.voltage_domain]
1650 type=VoltageDomain
1651 eventq_index=0
1652 voltage=3.3
```



###### b) 

Ο αριθμός των commited instructions ισούται με 5028.

> system.cpu_cluster.cpus.committedInsts           5028                       # Number of instructions committed



###### c)

Ο αριθμός των προσπελάσων της L2 cache ισούται με 332.

>system.cpu_cluster.l2.demand_accesses::.cpu_cluster.cpus.inst          332                       # number of demand (read+write) accesses

###### 3ο Ερώτημα

Σύμφωνα με το [documentation](https://www.gem5.org/documentation/) του gem5, τα μοντέλα in-order cpu που χρησιμοποιεί ο gem5 είναι  ο [SimpleCPU](https://www.gem5.org/documentation/general_docs/cpu_models/SimpleCPU) και ο [MinorCPU](https://www.gem5.org/documentation/general_docs/cpu_models/minor_cpu). 

Όλοι οι τύποι cpu κληρονομούν από την κλάση BaseCPU σχηματίζοντας την παρακάτω ιεραρχία :

- *BaseCPU*
  - BaseSimpleCPU
    - AtomicSimpleCPU
    - TimingSimpleCPU
  - MinorO3CPU
    - MinorCPU

Ουσιαστικά, έχουμε 3  in-order C++ μοντέλα CPU (ο O3 είναι out-of-order).  Atomic, Timing, και Minor. Όλα τα υπόλοιπα αποτελούν παραμετροποιήσεις αυτών των βασικών τύπων.

<u>**AtomicSimpleCPU**</u> : Το προεπιλεγμένο μοντέλο επεξεργαστή. Οι προσπελάσεις στην μνήμη γίνονται ακαριαία. Είναι ο γρηγορότερος από τους παραπάνω προσομοιωτές αλλά καθόλου ρεαλιστικός. Ιδιαίτερα χρήσιμος προκειμένου να *"bootαρει"* γρήγορα τα linux μέχρι ένα *checkpoint* και μετά *να αλλάξει με έναν πιο αργό επεξεργαστή*, προκειμένου να μετρηθούν κάποια *benchmark*.

<u>**TimingSimpleCPU**</u> : Οι προσπελάσεις μνήμης είναι ρεαλιστικές αλλα ο επεξεργαστής δεν έχει pipeline. Η προσομοίωση είναι γρήγορη αλλά πιο αργή από τον AtomicSimple. Οι caches κάνουν μεγάλη διαφορά και οδηγούν σε γρηγορότερους χρόνους προσπέλασης μνήμης.

<u>**MinorCPU**</u> : Αποτελεί ένα in-order μοντέλο με προκαθορισμένη διαδικασία διοχέτευσης αλλά προσαρμοζόμενες δομές δεδομένων και προσαρμοζόμενη συμπεριφορά εκτέλεσης.Το σταθερό pipeline του βοηθάει στην αναγνώριση και οπτικοποίηση μέσα σε αυτό της κάθε εντολής από μια προσομοίωση. Ο MinorCPU έχει επίσης υλοποιημένο έναν branch predictor που ενεργεί στο δεύτερο στάδιο του pipeline(Fetch2).



###### a)

Το c script που χρησιμοποιήσαμε είναι το παρακάτω :

~~~c
#include <stdio.h>

int main(){


	int num1 = 230 , num2 = 11 , sum = 0, t1 = 0, t2 = 1, nextTerm;
	
	for(int i=0;i<100000;i++){
	
		//calculate sum
		sum = sum + num1 * i + num2 * i * 2; 

	}

	
	printf("Result is %d", sum);
	
	return 0;
}
~~~

Τα αποτελέσματα χρόνου εκτέλεσης sim_seconds που προέκυψαν είναι τα εξής : 

- *MinorCPU* : 0.002340 sec
- *TimingSimpleCPU* : 0.006053 sec



###### b)

Η διαφορά στους χρόνους οφείλεται στις απανωτές προσπελάσεις στη μνήμη που περιλαμβάνει το προγράμμα. H *pipelined* λογική του *MinorCPU* μοντέλου υπερτερεί έναντι του *TimingSimpleCPU* , ο οποίος μπλοκάρει την εκτέλεση περιμένοντας το αποτέλεσμα της προσπέλασης της μνήμης.



###### c)

Αρχικά αλλάξαμε το *cpu_clock*

|                     | 1GHz         | 2GHz         | 4GHz         |
| :-----------------: | ------------ | ------------ | ------------ |
|    **MinorCPU**     | 0.002340 sec | 0.001182 sec | 0.000604 sec |
| **TimingSimpleCPU** | 0.006053 sec | 0.003039 sec | 0.001532 sec |

Παρατηρήσαμε ότι υπάρχει μεγάλη μείωση στους χρόνους εκτέλεσης, σχεδόν υποδιπλασιάζονται, και των δύο μοντέλων, όπως αναμενόταν.



Στη συνέχεια δοκιμάσαμε διαφορετικα μοντέλα μνημών στα 2GHz

|                     | LPDDR2_S4_1066_1x32 | DDR3_1600    | DDR4_2400    |
| :-----------------: | ------------------- | ------------ | ------------ |
|    **MinorCPU**     | 0.001193 sec        | 0.001182 sec | 0.001181 sec |
| **TimingSimpleCPU** | 0.003047 sec        | 0.003039 sec | 0.003039 sec |

Παρατηρούμε ότι υπάρχει *ελάχιστη εώς μηδαμινή διαφορά* στους χρόνους εκτέλεσης των **DDR3** & **DDR4** αλλά υπάρχει *μείωση* στους χρόνους σε σχέση με την **LPDDR2**. Ενώ περιμέναμε πιο διακριτή αύξηση των χρόνων εκτέλεσης, τα αποτελέσματα δεν το επιβεβαιώνουν. Είναι πολυ πιθανό η μικρή πολυπλοκότητα του προγράμματος να μην επιτρέπει να φανούν οι διαφορές.



#### Sources

[gem5](https://www.gem5.org/documentation/)

[Memory Models](https://nitish2112.github.io/post/gem5-memory-model/)

[CPU Types](https://cirosantilli.com/linux-kernel-module-cheat/#gem5-cpu-types)

[General Info about gem5](http://learning.gem5.org/book/)
