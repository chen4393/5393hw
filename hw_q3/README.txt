Source code for the stochastic simulation program. It should compile with any C compiler. The command-line parameters are:

 
aleae <file1> <file2> <trials> <time> <verbosity> <output file specified by user>
 
where <file1>     contains the name, initial quantity and threshold for each molecular type
<file2>     contains the reactants, products and rate constant for each reaction
<trials>    specifies how many trials to perform
<time>      specifies a time limit (this is if random time steps are taken -- set it to -1 to ignore time)
<verbosity> specifies how detailed the output should be; choose a number between 0 and 15, inclusive.
<output file> the output file specified by the user

Input files: 1. test.in(initial state and conditions for the probabilities we need to find) 
		2.test.r(reaction definitions)
Output file: test.out (or any filename specified by user)

sample command: > ./aleae test.in test.r 1000 100 0 test.out

Test steps:
1. make clean
2. make
3. pass the following command 
> ./aleae test.in test.r 1000 100 0 test.out
to the command line
4. check the test.out generated