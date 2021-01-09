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
Είναι η διοχέτευση ισχύος με τη μορφή ρεύματος διαρροής όταν το σύστημα δεν τροφοδοτείται η βρίσκεται σε standby mode. 
Η διοχέτευση ισχύος είναι ανεξάρτητη της συχνότητας και του "switching" του συστήματος. Η στατική ισχύ καταναλώνεται λόγω της διαρροής ρεύματος μέσω των τρανσίστορ. Υπάρχουν δύο είδη διαρροών και το μέγεθος κάθε ρεύματος διαρροής είναι ανάλογο με το πλάτος των τρανσίστορ και εξαρτάται από την λογική κατάσταση τους.Όταν η τάση πύλης(gate voltage) είναι μικρότερη από την τάση κατωφλίου (threshold voltage) προκύπτει το πρώτο είδος διαρροής, η διαρροή κατωφλίου (subthreshold leakage), συγκεκριμένα όταν ένα τρανσίστορ το οποίο είναι φαινομενικά στην κατάσταση off αφήνει ένα μικρό ρεύμα να περάσει ανάμεσα στην πηγή(source) και την εκροή(drain).Ο τύπος για να υπολογίσουμε το ρεύμα που δημιουργεί την τάση subthreshold: 
<img src= "https://github.com/AkisParousis/Computer_Architecture/blob/main/3rd%20Lab/IMG-fa137af69f877e98007176fbf3ef7dbc-V.jpg?raw=true">  
Ένα σημαντικό σημείο σε αυτόν τον τύπο είναι ότι το ρεύμα sub-threshold είναι εκθετικά ανάλογο του (Vgs-Vth). Κανονικά η τάση κατωφλίου (Vth) είναι έιναι αρκετά μεγάλη ώστε όταν η τάση Vgs ισούται με 0 το ρεύμα sub-threshold είναι πολύ μικρό. Ωστόσο με τις σημερινές μικρότερες γεωμετρίες και την μείωση στην τάση τροφοδοσίας, η Vth πρέπει επίσης να μειωθεί, με αποτέλεσμα η διαρροή ρεύματος που προκύπτει όταν η Vgs=0 είναι πλεον σημαντική. Από τον τύπο φαίνεται ότι μπορούμε να μειώσουμε το ρεύμα sub-threshold αυξάνοντας την Vth ή μειώνοντας την Vgs. Ωστόσο αυξάνοντας την Vth επηρεάζεται η επίδοση, για αυτό υπάρχει ένα μεγάλο "πάρε-δώσε" μεταξύ επιδόσεων και κατανάωσης ισχύος στην διαδικασία σχεδίασης. Ο δεύτερος τύπος διαρροής ονομάζεται διαρροή πηγής (gate leakage) και είναι το ρεύμα που ρέει μέσω της πηγής.

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

Ο υπολογισμός της κατανάλωσης ενέργειας προκύπτει από τον τύπο ( Subthreshold Leakage + Gate Leakage + Runtime Dynamic ) * sim_seconds και τα αποτελέσματα κάθε build βρίσκονται στο EnergyAll.

Παρακάτω δίνονται ορισμένα αποτελέσματα για συγκεκριμένα build


<table>
<thead>
<tr>
<th>specbzip</th>
<th>Score</th>
<th>spechmmer</th>
<th>Score</th>
<th>specmcf</th>
<th>Score</th>
<th>speclibm</th>
<th>Score</th>
<th>specsjeng</th>
<th>Score</th>
</tr>
</thead>
<tbody>
<tr>
<td>Default</td>
<td>123.823914 mJ</td>
<td>Default</td>
<td>91.318565 mJ</td>
<td>Default</td>
<td>93.621362 mJ</td>
<td>Default</td>
<td>231.895127 mJ</td>
<td>Default</td>
<td>649.633235 mJ</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>100.221764 mJ</td>
<td>L1D: 4-way</td>
<td>74.676564 mJ</td>
<td>L1D: 4-way</td>
<td>76.674230 mJ</td>
<td>L1D: 4-way</td>
<td>184.226590 mJ</td>  
<td>L1D: 4-way</td>
<td>515.013076 mJ</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>157.675267 mJ</td>  
<td>L1I: 64kB 2-way</td>
<td>115.341417 mJ</td>
<td>L1I: 64kB 2-way</td>
<td>109.753083 mJ</td>
<td>L1I: 64kB 2-way</td>
<td>302.372546 mJ</td>
<td>L1I: 64kB 2-way</td>
<td>854.355486 mJ</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>134.136488 mJ</td>
<td>L1I: 4-way</td>
<td>96.013992 mJ</td>
<td>L1I: 4-way</td>
<td>91.045831 mJ</td>
<td>L1I: 4-way</td>
<td>245.695555 mJ</td>
<td>L1I: 4-way</td>
<td>689.695666 mJ</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>123.823914 mJ</td>
<td>L2: 4MB 8-way</td>
<td>91.318565 mJ</td>
<td>L2: 4MB 8-way</td>
<td>93.621362 mJ</td>
<td>L2: 4MB 8-way</td>
<td>231.895127 mJ</td>
<td>L2: 4MB 8-way</td>
<td>649.633235 mJ</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>123.769042 mJ</td>
<td>L2: 2MB 4-way</td>
<td>91.314705 mJ</td>
<td>L2: 2MB 4-way</td>
<td>93.626185 mJ</td>
<td>L2: 2MB 4-way</td>
<td>231.867106 mJ</td>
<td>L2: 2MB 4-way</td>
<td>649.504959 mJ</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>152.208574 mJ</td>
<td>Cache Line Size: 128B</td>
<td>110.359947 mJ</td>
<td>Cache Line Size: 128B</td>
<td>115.692267 mJ</td>
<td>Cache Line Size: 128B</td>
<td>205.198952 mJ</td>
<td>Cache Line Size: 128B</td>
<td>525.719404 mJ</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>303.963183 mJ</td>
<td>Cache Line Size: 256B</td>
<td>214.112228 mJ</td>
<td>Cache Line Size: 256B</td>
<td>227.978289 mJ</td>
<td>Cache Line Size: 256B</td>
<td>329.617001 mJ</td>
<td>Cache Line Size: 256B</td>
<td>800.903844 mJ</td>
</tr>
</tbody>
</table>


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

Με βάση τα νέα δεδομένα καταλήξαμε στην παρακάτω συνάρτηση κόστους:

(1/1.1)*(x1/32kB) + (1/1.5)*(x2/256kB) + (1/1.05)*(assoc_1 / 2) + (1/1.05) * (assoc_2 / 4) + (c/16B) * (1/2.2) + E/10

* x1 : άθροισμα μεγεθών icache + dcache
* x2 : μέγεθος l2cache
* assoc_1 : αθροισμα icache_assoc + dcache_assoc
* assoc_2 : l2cache_assoc
* c : cache_line_size
* E : κατανάλωση ενέργειας

~~~
Οι συντελεστές και οι διαιρέτες επιλέχθηκαν με τέτοιο τρόπο ωστέ να κανονικοποιηθούν τα μεγέθη και να να μπορούν να συγκριθούν ως προς την επίδραση τους στο κόστος.
~~~

<p><strong>specbzip</strong></p>
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
<td>35.17</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>34.35</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>40.14</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>37.87</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>43.66</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>33.64</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>40.88</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>61.9</td>
</tr>
</tbody>
</table>

<p><strong>spechmmer</strong></p>
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
<td>25.57</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>25.85</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>28.85</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>26.98</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>24.25</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>22.22</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>29.35</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>44.03</td>
</tr>
</tbody>
</table>

<p><strong>specmcf</strong></p>
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
<td>26.53</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>27.09</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>27.72</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>25.92</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>33.21</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>25.34</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>30.93</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>46.66</td>
</tr>
</tbody>
</table>

<p><strong>speclibm</strong></p>
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
<td>70.82</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>69.37</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>81</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>75.52</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>89.32</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>67.5</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>59.28</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>70.35</td>
</tr>
</tbody>
</table>

<p><strong>specsjeng</strong></p>
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
<td>35,17</td>
</tr>
<tr>
<td>L1D: 4-way</td>
<td>34,35</td>
</tr>
<tr>
<td>L1I: 64kB 2-way</td>
<td>40,14</td>
</tr>
<tr>
<td>L1I: 4-way</td>
<td>37,87</td>
</tr>
<tr>
<td>L2: 4MB 8-way</td>
<td>43,66</td>
</tr>
<tr>
<td>L2: 2MB 4-way</td>
<td>33,64</td>
</tr>
<tr>
<td>Cache Line Size: 128B</td>
<td>40,88</td>
</tr>
<tr>
<td>Cache Line Size: 256B</td>
<td>61,9</td>
</tr>
</tbody>
</table>


#### Sources
[Static and Dynamic Power](https://www.vlsiguide.com/2020/04/static-and-dynamic-power-dissipation_20.html)  
[McPAT Documentation](https://github.com/HewlettPackard/mcpat)  
[Computer Architecture A Quantitative Approach]
[Various Power Dissipation Mechanisms and Leakage Current Reduction
Techniques in Deep-Submicron Technology]
[McPAT 1.0: An Integrated Power, Area, and Timing Modeling Framework for Multicore Architecture]


#### Review

Το τρίτο Lab μας βοήθησε να κατανοήσουμε καλύτερα την ενεργειακή ανάλυση του επεξεργαστή. Επίσης ήρθαμε σε επαφή και δουλέψαμε με ένα ακόμα εργαλείο μοντελοποίησης (McPat) που σε συνδυασμό με το gem5 μας βοήθησαν να δούμε καλύτερα την διαδικασία που ακολουθούν οι σχεδιαστές αλλά και τις απαιτήσεις που πρέπει να καλύψουν. Όπως και στο δεύτερο εργαστήριο έτσι και σε αυτό η αυτοματοποίηση διαδικασιών ήταν μονόδρομος ώστε να μπορέσουμε να παραδώσουμε όσων το δυνατό καλύτερο αποτέλεσμα σε όσο χρόνο είχαμε διαθέσιμο. Προσπαθήσαμε να τροποποιήσουμε το print_energy.py, αλλά όχι με επιτυχία. Μια παρατήρηση που έχουμε να κάνουμε είναι ότι πολλοί φοιτητές δεν έχουν την άνεση να διαχειριστούν τόσο εύκολα ένα μεγάλο όγκο δεδομένων, παρόλο που η εργασία είναι μιας πρώτης τάξης ευκαιρία να εξοικειωθούμε με αυτή τη διαδικασία, δεσμεύει αρκετό χρόνο που θα μπορούσαμε να αφιερώσουμε ώστε να αναλύσουμε σε βάθος τα διαθέσιμα δεδομένα και να τα βασίσουμε στις θεωρητικές μας γνώσεις.
