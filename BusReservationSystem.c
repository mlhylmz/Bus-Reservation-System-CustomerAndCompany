#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

char *randstring(size_t length) {

    static char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (int n = 0;n < length;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

anaMenu(){
    system("cls");
    printf("Otobus Sefer Rezervasyon Sistemi\n- - - - - - - -\n\n");
    printf("\tANA MENU\n1.FIRMA GIRISI\n2.MUSTERI GIRISI\n3.CIKIS");
    printf("\n\n--> Secim :");}

firmagirisi(){
    system("cls");
    printf("Otobus Sefer Rezervasyon Sistemi\n- - - - - - - -\n\n");
    printf("1.Otobus Ekle\n2.Sefer Bilgisi Ekle\n3.Sefer/Koltuk Bilgisi\n\n4.Ust Menuye Don\n");
    printf("\n-->Secim :");
}


MusteriGirisi(){
    system("cls");
    printf("Otobus Sefer Rezervasyon Sistemi\n- - - - - - - -\n\n");
    printf("1.Seferleri Listele\n2.Sefer Rezervasyon Yap\n3.Rezervasyon Bilgisi\n4.Ust Menuye Don");
    printf("\n\n-->Secim :");


}

    struct busSpecs{
        int kapasite;
        int kalanKapasite;
        char model[5];
        int busNo;
        int personelSayi;
        char busSefer[6];
        char busBaslangic[10];
        char busVaris[10];
        char baslangicSehir[15];
        char varisSehir[15];
        int hasilat;
        int biletUcret;
    }bus[50];

    struct userSpecs{
        char ad[20];
        char soyad[20];
        int rezNo;
        int koltukNo;
        char userKalkSaat[10];
        char userVarisSaat[10];
        char userKalkSehir[15];
        char userVarisSehir[15];
        int userUcret;

    }kullanici[50];
int main()
{
    int menusecim;
    int busStruct = 0;
    int userStruct = 0;
    anaMenuGit:
    anaMenu();
    scanf("%d",&menusecim);
    switch(menusecim){
        case 1://Firma girisi
            firmaGirisiGit:
            firmagirisi();
            scanf("%d",&menusecim);
            switch(menusecim){
                case 1://Otobüs ekle
                    system("cls");
                    printf("- Otobus Ekleme -\n\n");
                    printf("Otobus Kisi Sayisi : ");
                    scanf("%d",&bus[busStruct].kapasite);
                    bus[busStruct].kalanKapasite = bus[busStruct].kapasite;
                    printf("Otobus Modeli (Max. 5) : ");
                    scanf("%s",bus[busStruct].model);
                    bus[busStruct].busNo= busStruct+1;
                    printf("Otobuse %d numarasi verildi.\n",bus[busStruct].busNo);
                    if(bus[busStruct].kapasite <= 30){
                        bus[busStruct].personelSayi = 2;
                    }

                    else
                        bus[busStruct].personelSayi = 3;
                    printf("Personel sayisi  %d olarak ayarlandi.\n\n",bus[busStruct].personelSayi);

                    busStruct = busStruct+1;
                    printf("Enter'a basiniz.");
                    getch();
                    goto firmaGirisiGit;
                    break;
                case 2:;//Sefer Bilgisi Ekle

                    system("cls");
                    char deneme[4];
                    char seferNo[]= "37";
                    strcpy(deneme,randstring(4));
                    strcat(seferNo,deneme);
                    printf("Hangi nolu otobuse bu bilgileri gireceksiniz : ");
                    int busSecim;
                    scanf("%d",&busSecim);
                    strcat(bus[busSecim-1].busSefer,seferNo);
                    printf("Otobus seferi kacta baslayacak : ");
                    scanf("%s",&bus[busSecim-1].busBaslangic);
                    strcat(bus[busSecim-1].busBaslangic,":37");
                    strcpy(bus[busSecim-1].busVaris,bus[busSecim-1].busBaslangic);

                    if(bus[busSecim-1].kapasite<=30)
                        strcat(bus[busSecim-1].busVaris," +2");
                    else
                        strcat(bus[busSecim-1].busVaris," +4");

                    printf("Otobusun kalkacagi sehir : ");
                    scanf("%s",bus[busSecim-1].baslangicSehir);
                    printf("Otobusun varacagi sehir : ");
                    scanf("%s",bus[busSecim-1].varisSehir);
                    printf("Beklenen Hasilat : ");
                    scanf("%d",&bus[busSecim-1].hasilat);
                    printf("Bilet Ucreti : ");
                    scanf("%d",&bus[busSecim-1].biletUcret);
                    printf("Bilgiler basariyla girildi. Enter'a basiniz.");
                    getch();
                    goto firmaGirisiGit;

                    break;
                case 3://Sefer Koltuk Bilgisi

                    system("cls");

                    for(int i=0 ; i<busStruct ; i++){
                        printf("OTOBUS %d \n",bus[i].busNo);}
                    koltuktekrar:
                    printf("\nHangi Otobusu Goreceksiniz : ");
                    scanf("%d",&busSecim);
                    if(busSecim>busStruct){
                        system("cls");
                        goto koltuktekrar;
                    }
                    system("cls");
                    printf("Kalan Koltuk :%d\n",bus[busSecim-1].kalanKapasite);
                    printf("Otobus Modeli :%s\n",bus[busSecim-1].model);
                    printf("Kalkis Saati : %s\nVaris Saati :%s\n",bus[busSecim-1].busBaslangic,bus[busSecim-1].busVaris);
                    printf("Sefer : %s - %s \n",bus[busSecim-1].baslangicSehir,bus[busSecim-1].varisSehir);
                    printf("Bilet Ucreti :%d",bus[busSecim-1].biletUcret);
                    getch();
                    goto firmaGirisiGit;


                    break;
                case 4://Üst menü
                    goto anaMenuGit;
                default:
                    goto firmaGirisiGit;
                    break;}
                break;
    //-----------------------------------------------------
        case 2 ://Müþteri Giriþi
            musteriGirisiGit:
            system("cls");
            MusteriGirisi();
            scanf("%d",&menusecim);
            switch(menusecim){
                case 1://sefer listele
                    system("cls");
                    for(int i=0;i<busStruct ; i++){
                        printf("%d. Otobus VVVVVV\n",i+1);
                        printf("Kalan Koltuk :%d\n",bus[i].kalanKapasite);
                        printf("Otobus Modeli :%s\n",bus[i].model);
                        printf("Kalkis Saati : %s\nVaris Saati :%s\n",bus[i].busBaslangic,bus[i].busVaris);
                        printf("Sefer : %s - %s \n",bus[i].baslangicSehir,bus[i].varisSehir);
                        printf("Bilet Ucreti :%d",bus[i].biletUcret);
                        printf("\n\n----\n");
                    }
                    getch();
                    goto musteriGirisiGit;
                case 2://rezervasyon yap
                    system("cls");
                    printf("Otobus numarasi giriniz. \nOtobus numarasini bilmiyorsaniz 'Sefer Listele' bolumunden bakiniz.\nNumara :");
                    int noSecim;
                    scanf("%d",&noSecim);
                    printf("-- Rezervasyon Sayfasi -- \n\n");
                    printf("Ad :");
                    scanf("%s",kullanici[userStruct].ad);
                    printf("Soyad :");
                    scanf("%s",kullanici[userStruct].soyad);
                    koltukTekrar:
                    printf("Alinacak koltuk numarasi :");
                    int tempNo;
                    scanf("%d",&tempNo);
                    if(tempNo > bus[userStruct].kapasite){
                        printf("Lutfen gecerli bir koltuk numarasý giriniz.");
                        goto koltukTekrar;
                    }
                    kullanici[userStruct].koltukNo = tempNo;
                    kullanici[userStruct].rezNo = userStruct+1001;
                    printf("Rezervasyon numaraniz :%d",kullanici[userStruct].rezNo);
                    strcpy(kullanici[userStruct].userKalkSaat,bus[userStruct].busBaslangic);
                    strcpy(kullanici[userStruct].userVarisSaat,bus[userStruct].busVaris);
                    strcpy(kullanici[userStruct].userKalkSehir,bus[userStruct].baslangicSehir);
                    strcpy(kullanici[userStruct].userVarisSehir,bus[userStruct].varisSehir);
                    kullanici[userStruct].userUcret = bus[userStruct].biletUcret;
                    userStruct= userStruct+1;
                    getch();
                    goto musteriGirisiGit;
                    break;

                case 3://rezervasyon listele
                    printf("Rezervasyon numaranizi giriniz :");
                    int tempRezNo;
                    scanf("%d",&tempRezNo);
                    for(int i=0; i<=100 ;i++){
                        if(kullanici[i].rezNo == tempRezNo){
                            system("cls");
                            printf("Ad :%s\nSoyad :%s",kullanici[i].ad,kullanici[i].soyad);
                            printf("\nRezervasyon Numarasi :%d",kullanici[i].rezNo);
                            printf("\nKoltuk Numarasi :%d",kullanici[i].koltukNo);
                            printf("\nKalkis Saati :%s",kullanici[i].userKalkSaat);
                            printf("\nSefer :%s - %s",kullanici[i].userKalkSehir,kullanici[i].userVarisSehir);
                        }
                    }
                    printf("\nMenuye donmek icin Enter'a basin.");
                    getch();
                    goto anaMenuGit;


            }
            break;
                case 3:
                    break;
        default :
            goto anaMenuGit;

    }


    system("cls");
    printf("Bizi tercih ettiginiz icin tesekkurler :))\n\n\n\t\tIYI GUNLER");
    getch();

    return 0;
}
