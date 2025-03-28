

# MPI + OpenMP Paralel İşlem Projesi

Bu proje, Docker ortamında **MPI** (Message Passing Interface) ve **OpenMP** (Open Multi-Processing) kullanarak paralel işlem yapmayı amaçlamaktadır. OpenMP, aynı düğümdeki iş parçacıklarıyla paralel işlem yaparken, MPI düğümler arasında veri iletimi sağlayarak daha büyük veri setlerinde paralel işlem gücünü artırır.

## Proje İçeriği

Bu projede üç ana dosya bulunmaktadır:

1. **`docker-compose.yml`**: Docker konteynerlerini yöneten yapılandırma dosyası.
2. **`Dockerfile`**: Gerekli yazılımların yüklendiği ve C programının derlendiği yapılandırma dosyası.
3. **`main.c`**: MPI ve OpenMP kullanarak paralel işlem gerçekleştiren ana C programı.

---

## Projeyi Çalıştırma

### Gereksinimler

- Docker ve Docker Compose yüklü olmalıdır.
- OpenMPI ve OpenMP destekli bir ortam gereklidir (Docker bu gereksinimleri otomatik olarak sağlar).

### Adımlar

1. **Projeyi Çekme**:
    ```bash
    git clone <repo_url>
    cd <repo_name>
    ```

2. **Docker Compose ile Ortamı Başlatma**:
   Projeyi çalıştırmak için, Docker Compose kullanarak ortamı başlatabilirsiniz. Aşağıdaki komutları sırayla çalıştırın:
   
    ```bash
    docker-compose up --build
    ```

    Bu komut, gerekli tüm servisleri (ana düğüm ve işçi düğümleri) başlatacaktır. Docker Compose, `docker-compose.yml` dosyasındaki yapılandırma ile konteynerleri oluşturur.

3. **Programın Çalıştığını Kontrol Etme**:
   Program, her bir düğümde işlem yaparak paralel işlemi başlatacak ve sonuçları ana düğüme (master node) gönderecektir. Çıktıları terminal üzerinden görebilirsiniz.

---

## Performans Karşılaştırması: MPI vs OpenMP

Bu projede **MPI** ve **OpenMP**'nin paralel işlemdeki performans farklarını karşılaştırdık.

### MPI:
- MPI, farklı düğümler arasında veri iletimi sağlar ve her düğümde bağımsız bir işlem yapılır. 
- Büyük veri setlerinde, veri transferi ve işlemler arasında paralellik sağlar.
- Ancak, ağ üzerinden veri iletimi zaman alabilir ve küçük veri setlerinde bu, performans kaybına yol açabilir.

### OpenMP:
- OpenMP, aynı düğümdeki iş parçacıklarını paralelleştirir. 
- Her bir düğümde işlemci çekirdekleri arasında paralel işlem yapar.
- Bu, küçük veri setlerinde daha verimli olabilir, çünkü işlemcinin kendi içinde paralel işlem yapılır.
- Ancak, çok büyük veri setlerinde OpenMP tek başına yeterli olmayabilir; bu durumda MPI'nin gücü daha belirgindir.

---

## Proje Yapısı

- **`docker-compose.yml`**: Docker Compose ile ana düğüm ve worker düğümlerinin yönetildiği yapılandırma dosyası.
- **`Dockerfile`**: Docker konteyneri için gerekli yazılımların yüklendiği ve C programının derlendiği dosya.
- **`main.c`**: MPI ve OpenMP kullanarak paralel işlem yapacak olan ana program.

---

## Lisans

Bu proje, MIT Lisansı ile lisanslanmıştır. Detaylı bilgi için [LICENSE](LICENSE) dosyasına bakabilirsiniz.

---

### YouTube Video Bağlantısı

Projeyi nasıl çalıştıracağınızı ve performans farklarını daha detaylı bir şekilde anlatan videomuzu izlemek için aşağıdaki bağlantıyı ziyaret edebilirsiniz:

[YouTube Videosu](<https://www.youtube.com/watch?v=ELmo7Iyo9ZY>)
