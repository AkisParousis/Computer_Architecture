### ΑΡΧΙΤΕΚΤΟΝΙΚΗ ΥΠΟΛΟΓΙΣΤΩΝ

#### **ΠΑΡΟΥΣΗΣ ΣΤΑΥΡΟΣ ΔΗΜΟΣ 8892 / ΠΟΥΝΙΩΤΗΣ ΣΤΑΥΡΟΣ 8995**  
##### **Εργαστήριο Β / Ομάδα 17**



#### **3η Εργαστηριακή Άσκηση**

##### Βήμα 1ο
###### 1ο Ερώτημα

Η διοχέτευση ισχύος ταξινομείται σε δύο κατηγορίες: 

* Static power (leakage power) dissipation 
* Dynamic power dissipation

Το άθροισμα της συνολικής διοχέτευσης ισχύος ισούται με το άθροισμα των δύο παρπάνω παραγόντων.

*Static power dissipation*
Είναι η διοχέτευση ισχύος με τη μορφή ρεύματος διαρροής όταν το σύστημα δεν τροφοδοτείται η βρίσκεται σε stanby mode. 
Η διοχέτευση ισχύος είναι ανεξάρτητη της συχνότητας και του "switching" του συστήματος. Εξαρτάται μόνο από τη γεωμετρία και τις τεχνολογίες του επεξεργαστή.

*Dynamic power dissipation*
Οφείλεται σε δύο παράγοντες , την switching ισχύ και την short-circuit ισχύ.
Η πρώτη διοχετεύεται όταν φορτίζονται και ξεφορτίζονται οι χωρητικότητες του συστήματος. Κατά τη φόρτιση του πυκνωτή CL μέσω του pmos transistor η τάση του ανεβαίνει από το 0 στο Vdd και ένα συγκεκριμένο ποσό ενέργειας αντλείται από το τροφοδοτικό. Μέρος της ενέργειας αυτής διοχετεύεται στη pmos συσκευή και η υπόλοιπη αποθηκεύεται στον πυκνωτή.Η ίδια διαδικασία ισχύει και κατά την αποφόρτιση(nmos).
Η δεύτερη ειναι η ισχύς που διοχετεύται όταν η πύλη των transistor αλλάζει κατάσταση. Για ένα μικρό χρονικο διάστημα t δημιουργείται ένα βραχυκύκλωμα μεταξύ της παροχής τάσης και της γείωσης κατά τη διάρκεια του οποίου και οι δυο συσκευές είναι στο ON (nmos, pmos).

Όταν τρέχουμε διαφορετικά προγράμματα στον ίδιο επεξεργαστή η leakage power δεν αλλάζει καθώς εξαρτάται μόνο από την τεχνολογία του επεξεργαστή. Αυτό που αλλάζει είναι η δυναμική ισχύς επειδή αλλάζει η switching activity και επομένως η switching frequency.

Όταν ένα πρόγραμμα αυξάνεται χρονικά, αυξάνεται και οι switching activity και switching frequency. Άρα αυξάνεται και η δυναμική ισχύς που καταναλώνεται.


###### 2ο Ερώτημα

Έστω ότι έχουμε ένα σύστημα με μπαταρία συγκεκριμένης χωρητικότητας και οι δύο επεξεργαστές καταναλώνουν 4 και 40 Watt αντίστοιχα. Αν ο δεύτερος επεξεργαστής εκτελεί τα προγράμματα σε ταχύτερο χρόνο από τον πρώτο και μείνει σε idle mode, μπορεί να δώσει καλύτερα αποτελέσματα όσον αφορά το *energy_efficiency*. Αυτό μπορεί να ελεγχθεί από τον τύπο: 
~~~
idle_working_time *  idle_power_consumption + work_power_consumption * work_time
~~~

Ο McPAT είναι ένας emulator ο οποίος σύμφωνα με τα χαρακτηριστικά και τις παραμέτρους μιας αρχιτεκτονικής επεξεργαστή επιστρέφει αποτελέσματα σχετικά με τη κατανάλωση ισχύος , την γεωμετρία του cpu κ.α.
Αυτό πού δεν μπορεί να επιστρέψει είναι ο χρόνος εκτέλεσης ενός προγράμματος ή το idle_time του cpu όταν εκτελείται το πρόγραμμα. Αυτός είναι ο λόγος που δε μπορεί να δώσει επαρκείς πληροφορίες για το ερώτημα μας.


###### 3ο Ερώτημα

<table>
<thead>
<tr>
<th>Processors</th>
<th>Technology</th>
<th>Core clockrate</th>
<th>Total Leakage</th>
<th>Peak Dynamic</th>
<th>Total Power Consumption</th>
</tr>
</thead>
<tbody>
<tr>
<td>XEON</td>
<td>65nm</td>
<td>3400MHz</td>
<td>36.8319 W</td>
<td>98.1063 W</td>
<td>134.938 W</td>
</tr>
<tr>
<td>ARM A9</td>
<td>40nm</td>
<td>2000MHz</td>
<td>0.108687 W</td>
<td>1.6332 W</td>
<td>1.74189 W</td>
</tr>
</tbody>
</table>

Η συνολική κατανάλωση ισχύος του *ARM A9* ισούται με 1.74189 W. Υποθέτοντας ότι ο XEON είναι 40 φορές ταχύτερος τότε ο ARM θα καταναλώνει κατά τη διάρκεια εκτέλεσης του προγράμματος 40 * 1.74189 W = 69,9276 W < 134.938 W. Ακόμη κι αν ο XEON μένει idle το υπόλοιπο χρονικό διάστημα ο ARM είναι περισσότερο energy efficient από τον XEON.



##### Βήμα 2ο
###### 1ο Ερώτημα

Για κάθε build που είχαμε σχεδιάσει στην [Εργαστηριακή άσκηση 2](https://github.com/AkisParousis/Computer_Architecture/tree/main/2nd%20Lab/Results) πήραμε μέσω του McPAT τα χαρακτηριστικά Area, Subthreshold Leakage, Gate Leakage, Runtime Dynamic και μέσω του stats.txt το sim_seconds επειδή το Delay είναι ο χρόνος εκτέλεσης του προγράμματος.  
Από αυτά τα χαρακτηριστικά προέκυψαν τα αρχεία [EnergyAll](https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/energyAll.txt) και [AreaAll](https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/areaAll.txt)

Ο υπολογισμός της κατανάλωσης ενέργειας προκύπτει από τον τύπο ( Subthreshold Leakage + Gate Leakage + Runtime Dynamic ) * Area * sim_seconds


###### 2ο Ερώτημα

Παρακάτω παρουσιάζουμε τα γραφήματα με την επίδραση των μεταβολών των χαρακτηριστικών που μελετήσαμε στην εργαστηριακή άσκηση 2 στο peak power :

*cache_line_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/cache_line_size_pp.png?raw=true">


*icache_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/icache_size_pp.png?raw=true">


*icache_assoc*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/icache_assoc_pp.png?raw=true">


*dcache_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/dcache_size_pp.png?raw=true">


*dcache_assoc*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/dcache_assoc_pp.png?raw=true">


*l2_size*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/L2cache_size_pp.png?raw=true">


*l2_assoc*

<img src="https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/Results/L2cache_assoc_pp.png?raw=true">

#### Sources
[Static and Dynamic Power](https://www.vlsiguide.com/2020/04/static-and-dynamic-power-dissipation_20.html)  
[McPAT Documentation](https://github.com/HewlettPackard/mcpat)  
[Computer Architecture A Quantitative Approach]  
