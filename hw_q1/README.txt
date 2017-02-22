Source code for the stochastic simulation program. It should compile with any C compiler. The command-line parameters are:

 
aleae <file1> <file2> <trials> <time> <verbosity> <output file>
 
where <file1>     contains the name, initial quantity and threshold for each molecular type
<file2>     contains the reactants, products and rate constant for each reaction
<trials>    specifies how many trials to perform
<time>      specifies a time limit (this is if random time steps are taken -- set it to -1 to ignore time)
<verbosity> specifies how detailed the output should be; choose a number between 0 and 15, inclusive.
<output file> the output file specified by the user

1. Question A
Input files: 1. test.in(initial state and conditions for the probabilities we need to find) 
		2.test.r(reaction definitions)
Output file: test.out

sample command: > ./aleae question_a.in question_a.r 1000 -1 0 qa.out

Test steps:
1. make clean
2. make
3. pass the following command > ./aleae test.in test.r 1000 -1 0 qa.out to the command line
4. check the qa.out generated

2. Question B
Input files: 1. question_b.in 2. question_b.r
Output file: b.out

Test steps:

1. make clean
2. make
3. modify the question_b.in file 
4. pass the following command > ./aleae question_b.in question_b.r 1000 5 0 qb.out to the command line
5. check the qa.out generated


For example, if we want to get the probablility distribution of X1, we need to edit question_b.in as follows:
a 6 LE 0
b 6 LE 10
c 6 LE 10
pass the command ./aleae question_b.in question_b.r 1000 5 0 qb.out
check the result from q2,out and then record the result of Pr(a <= 0).

Next, edit the question_b.in as follows:
a 6 LE 1
b 6 LE 10
c 6 LE 10
and record Pr(a <= 1)

and so on, until 
a 6 LE 10
b 6 LE 10
c 6 LE 10
and record Pr(a <= 10)

./aleae question_b.in question_b.r 1000 5 0 q2.out
In other words, we need to constantly change the initial state in question_b.in file!                                                                                                                      
