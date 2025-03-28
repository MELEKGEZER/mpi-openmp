FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    openmpi-bin \
    openmpi-common \
    libopenmpi-dev \
    gcc \
    build-essential

COPY main.c /main.c

RUN mpicc -fopenmp main.c -o mpi_openmp.out

ENV OMPI_ALLOW_RUN_AS_ROOT=1
ENV OMPI_ALLOW_RUN_AS_ROOT_CONFIRM=1

CMD ["mpirun", "--oversubscribe", "-np", "4", "./mpi_openmp.out"]