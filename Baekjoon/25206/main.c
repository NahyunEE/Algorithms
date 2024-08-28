#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct obj{
	char name[51];
	float hakjum;
	char score[3];
};

int changeScore(const char *str) {
    if (strcmp(str, "A0") == 0) return 0;
    if (strcmp(str, "A+") == 0) return 1;
    if (strcmp(str, "B0") == 0) return 2;
    if (strcmp(str, "B+") == 0) return 3;
    if (strcmp(str, "C0") == 0) return 4;
    if (strcmp(str, "C+") == 0) return 5;
    if (strcmp(str, "D0") == 0) return 6;
    if (strcmp(str, "D+") == 0) return 7;
    if (strcmp(str, "F") == 0) return 8;
    if (strcmp(str, "P") == 0) return 9;
    return -1; 
}



int main(int argc, char *argv[]) {
	
	
	struct obj BuRupDa;
	
	float hakjum_sum=0.0;
	
	float score_sum = 0.0;
	
	int i=0;
	
	for(i=0; i< 20; ++i){
		
		scanf("%50s %f %2s", BuRupDa.name, &BuRupDa.hakjum, BuRupDa.score);
		
		int temp = changeScore(BuRupDa.score);
		
		if(temp != 9){
			hakjum_sum+= BuRupDa.hakjum;
		}
		
        switch (temp) {
            case 0: score_sum += (BuRupDa.hakjum * 4.0); break; // A0
            case 1: score_sum += (BuRupDa.hakjum * 4.5); break; // A+
            case 2: score_sum += (BuRupDa.hakjum * 3.0); break; // B0
            case 3: score_sum += (BuRupDa.hakjum * 3.5); break; // B+
            case 4: score_sum += (BuRupDa.hakjum * 2.0); break; // C0
            case 5: score_sum += (BuRupDa.hakjum * 2.5); break; // C+
            case 6: score_sum += (BuRupDa.hakjum * 1.0); break; // D0
            case 7: score_sum += (BuRupDa.hakjum * 1.5); break; // D+
            case 8: score_sum += 0;break; //F
            case 9: break; //P
            default: break;
        }
				
	}
	if (hakjum_sum > 0) { 
        float result = score_sum / hakjum_sum;
        printf("%f\n", result);
    }
	
	return 0;
}
