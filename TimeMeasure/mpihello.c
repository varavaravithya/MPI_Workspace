#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
  
  double start, end;
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);
  
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  
  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  start = MPI_Wtime();
  
  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);
  
  // Print off a hello world message
  printf("Hello world from processor %s, rank %d"
	 " out of %d processors\n",
           processor_name, world_rank, world_size);
  
  // Finalize the MPI environment.
  end = MPI_Wtime();
    
  if (world_rank == 0) { /* use time on master node */
    printf("Runtime = %f seconds\n", end-start);
  }
  
  MPI_Finalize();
}
