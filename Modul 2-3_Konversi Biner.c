#include <stdio.h>
#include <stdlib.h>

void menu ();
int biner_desimal(int biner);
int desimal_biner(int desimal);
int cek_input(char input[20]);
int cek_biner(int biner);
void judul();
void menu_satu();
void menu_dua();


int main(){
	
    int pilihan=0,input_desimal=0,cek=0,lagi=0,input_biner=0;
    char inputan[20];
    
    do{
    	system("color 09");
        judul();
        menu();
        do{
        	printf("\t         +=========================================+\n");
        	printf("\t          Masukan pilihan anda\t: ");
        	scanf("%s",inputan);
        	pilihan = cek_input(inputan);
        	if(pilihan < 1 || pilihan > 2){
           		printf("\n\n\t          Masukan angka yang ada pada pilihan!\n");
        	}
    	}while(pilihan < 1 || pilihan > 2);
        
        if(pilihan == 1){
        	system("cls");
            menu_satu();
            do{
                printf("\n\n\t         +=========================================+\n");
                printf("\t          Masukan angka (desimal) : ");
                scanf(" %[^\n]s",inputan);
                input_desimal =cek_input(inputan);
                input_biner = desimal_biner(input_desimal);
                if(input_desimal == -1){
                    printf("\n\n\t          Input salah!Ulangi\n");
            	}
        	}while(input_desimal == -1);
        
        printf("\n\t         +=========================================+\n");
        printf("\t          angka biner\t: %d\n",input_biner);
   		}
   		
    	if (pilihan == 2){
    		system("cls");
    		menu_dua();
        	do{
            	printf("\n\n\t         +=========================================+\n");
            	printf("\t          Masukan angka (biner)\t: ");
            	scanf(" %[^\n]s",inputan);
            	input_biner = cek_input(inputan);
            	cek = cek_biner(input_biner);
            	input_desimal = biner_desimal(input_biner);
            	if(input_biner == -1){
                printf("\n\n\t          Input salah!Ulangi\n");
            	}
            	if(cek == 1){
                	printf("\n\n\t          Angka bukan dalam bentuk biner\n");
                	printf("\t          Silahkan coba lagi\n");
            	}
        	}while(cek == 1 || input_biner == -1);
        
        printf("\n\n\t         +=========================================+\n");
        printf("\t          angka desimal\t: %d\n",input_desimal);
    	}
    	
    	do{
        	printf("\n\n\t         +=========================================+\n");
        	printf("\t         | Konversi angka lagi?                    |\n");
        	printf("\t         | 1.YA                                    |\n");
        	printf("\t         | 2.TIDAK                                 |\n");
        	printf("\t         +=========================================+\n");
        	printf("\t          (Ketik 1 untuk Ya dan 2 untuk Tidak) : ");
        	scanf(" %[^\n]s",inputan);
        	lagi = cek_input(inputan);
        	if(lagi < 1 || lagi > 2){
            	printf("\n\n\t         +=========================================+\n");
            	printf("\t          Input salah! Masukan input yang benar ulang!\n");
        	}
    	}while(lagi < 1 || lagi > 2);
    
        if(lagi == 1){
            system("cls");
        }
    }while(lagi == 1);
    
    system("cls");
    printf("\n\n\t         +=========================================+\n");
    printf("\t         |==============|Terima Kasih|=============|\n");
    printf("\t         +=========================================+\n");
}

void menu (){
		printf("\n\n     `~`~`~`~`~`~`<<Silahkan Pilih Menu Konversi di Bawah>>`~`~`~`~`~`~`\n\n"
		   	   "      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
		   	   "       1.KONVERSI DESIMAL KE BINER         2.KONVERSI BINER KE DESIMAL\n"
		   	   "      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<       <<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
}

int biner_desimal(int biner){
	int sisa=0,angka=0,desimal = 0,bobot = 1;
	angka=biner;
    while(angka !=0){
        sisa = angka % 10;
        desimal = desimal + sisa *bobot;
        angka = angka / 10;
        bobot = bobot*2;
    }
	return desimal;
}
int desimal_biner(int desimal){
    int biner = 0;
    int sisa,angka,kali = 1;
    angka = desimal;
    while (angka != 0){
        sisa = angka % 2;
        biner = biner + sisa * kali;
        angka = angka / 2;
        kali = kali*10;
    }
    return biner;
}
int cek_input(char input[20]){
    int angka;
    char *pointer;

    angka = strtol(input,&pointer,10);
    if(!angka){
        return -1;
    }
    else{
        return angka;
    }
}
int cek_biner(int biner){
    int sisa;
    while(biner > 0){
        sisa = biner % 10;
        if(sisa != sisa * sisa){
            return 1;
        }
        biner = biner / 10;
    }
    return 0;
}
void judul(){
	printf(" ==============================(             )================================\n"
		   " =============================================================================\n"
		   " <><><><><><><><><><><><><><> M E N U   U T A M A <><><><><><><><><><><><><><>\n"
		   " =============================================================================\n"
	       " |                 PROGRAM KONVERSI BILANGAN BINER & DESIMAL                 |\n"
	       " |                                ^^^^^^^^^                                  |\n"
	       " |                               KELOMPOK 15                                 |\n"
	       " =============================================================================\n"
		   " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

void menu_satu(){
	printf(" ==============================(             )================================\n"
		   " =============================================================================\n"
		   " <><><><><><><><><><><><><> M E N U   P E R T A M A <><><><><><><><><><><><><>\n"
		   " =============================================================================\n"
	       " |                                                                           |\n"
	       " |                    KONVERSI BILANGAN DESIMAL KE BINER                     |\n"
	       " |                                                                           |\n"
	       " =============================================================================\n"
		   " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

void menu_dua(){
	printf(" ==============================(             )================================\n"
		   " =============================================================================\n"
		   " <><><><><><><><><><><><><><> M E N U   K E D U A <><><><><><><><><><><><><><>\n"
		   " =============================================================================\n"
	       " |                                                                           |\n"
	       " |                    KONVERSI BILANGAN BINER KE DESIMAL                     |\n"
	       " |                                                                           |\n"
	       " =============================================================================\n"
		   " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

