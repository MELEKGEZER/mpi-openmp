#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int data = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("******************************\n");
        printf("*  Paralel İşlem Başlatılıyor  *\n");
        printf("******************************\n");

        data = 0;
        printf("[Ana Düğüm] Başlangıç verisi: %d\n", data);

        int initial_value = 10;
        MPI_Send(&initial_value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("[Ana Düğüm] Gönderilen ilk veri: %d → Düğüm 1'e yollandı\n\n", initial_value);

        int final_result;
        MPI_Recv(&final_result, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("[Ana Düğüm] Alınan nihai değer: %d - Başarıyla sonuca ulaşıldı!\n", final_result);

        printf("******************************\n");

    } else {
        int received_data;
        MPI_Recv(&received_data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("[Düğüm %d] Gelen veri: %d\n", rank, received_data);

        int updated_value = received_data;
        printf("[Düğüm %d] 4 farklı iş parçacığı ile işlem yapılıyor...\n", rank);

        #pragma omp parallel for
        for (int i = 0; i < 4; i++) {
            #pragma omp critical
            printf("[Düğüm %d] İş parçacığı %d çalışmaya başladı...\n", rank, i);
            updated_value += 5;
        }

        printf("[Düğüm %d] Hesaplanan yeni değer: %d\n", rank, updated_value);

        if (rank == size - 1) {
            MPI_Send(&updated_value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            printf("[Düğüm %d] Sonuç ana düğüme gönderildi!\n\n", rank);
        } else {
            MPI_Send(&updated_value, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
            printf("[Düğüm %d] Sonuç bir sonraki düğüme gönderildi: Düğüm %d\n\n", rank, rank + 1);
        }
    }

    MPI_Finalize();
    return 0;
}
