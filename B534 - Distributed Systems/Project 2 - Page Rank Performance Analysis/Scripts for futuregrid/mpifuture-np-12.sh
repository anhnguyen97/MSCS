#! /bin/bash
# Script for running the mpi_main
date >> outputBM
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.1K0 -n 10 >> outputBM
echo Finished np 12 1K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.10K0 -n 10 >> outputBM
echo Finished np 12 10K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.20K0 -n 10 >> outputBM
echo Finished np 12 20K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.30K0 -n 10 >> outputBM
echo Finished np 12 30K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.40K0 -n 10 >> outputBM
echo Finished np 12 40K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.50K0 -n 10 >> outputBM
echo Finished np 12 50K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.60K0 -n 10 >> outputBM
echo Finished np 12 60K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.70K0 -n 10 >> outputBM
echo Finished np 12 70K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.80K0 -n 10 >> outputBM
echo Finished np 12 80K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.90K0 -n 10 >> outputBM
echo Finished np 12 90K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.100K0 -n 10 >> outputBM
echo Finished np 12 100K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.500K0 -n 10 >> outputBM
echo Finished np 12 500K0
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.1M -n 10 >> outputBM
echo Finished np 12 1M
mpirun -hostfile $PBS_NODEFILE -np 12 ./mpi_main -i pagerank.input.2M -n 10 >> outputBM
echo Finished np 12
