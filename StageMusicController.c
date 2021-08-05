/*
* StageMusicController.c
* Coco07
* 2021.4.12 
*/

#include <windows.h>
#include <stdio.h>
#include "ccio.h"

#define AUDIO_LIST_FILE "audio.list"
#define MAX_FILE_NUM 200
#define MAX_FILE_NAME 300 

int main(){
	system("title StageMusicController - Coco07");
	printf("StageMusicController - Coco07 - 2021.4.12\nSimply play .wav audio.\n\n");
	FILE *fp = fopen(AUDIO_LIST_FILE, "r");
	if(!fp){
		printf("Error:Cannot read file \"%s\".\n", AUDIO_LIST_FILE);
		goto main_ret;
	}
	char filelist[MAX_FILE_NUM][MAX_FILE_NAME];
	int n = -1;
	while(!feof(fp)){
		fscanf(fp, "%s", filelist[++n]);
		printf("(%d)%s\n", n+1, filelist[n]);
	}
	if(fclose(fp) == EOF){
		printf("Error: Cannot close the file \"%s\".\n", AUDIO_LIST_FILE);
//		goto main_ret;
	}
	cprintf(RED, "Now Playing");
	cprintf(GREEN, "	Coming soon\n");
	int i = -1, b = 1;
	while(i <= n){
		if(b){
			if(i >= 0) cprintf(RED, "(%d)%s", i+1, filelist[i]);
			if(i < n) cprintf(GREEN, "	(%d)%s", i+2, filelist[i+1]);
			printf("\n");
			b = 0;
		}
		for(int key = 8; key <= 255; ++key){
			if(GetAsyncKeyState(key)&1){
				if((key == VK_RETURN || key == VK_RIGHT) && i < n){
					++i;
					b = 1;
				}
				else if(key == VK_LEFT && i >= 0){
					--i;
					b = 1;
				}
				else if(key >= 48 && key <= 57 && key <= 49+n){
					i = key-49;
					b = 1;
				}
				else if(key == VK_SPACE){
					PlaySound(NULL, NULL, 0);
					goto while_end; 
				}
				else if(key == VK_UP){
					keybd_event(0xAF, 0, 0, 0);
					keybd_event(0xAF, 0, KEYEVENTF_KEYUP, 0);
				}
				else if(key == VK_DOWN){
					keybd_event (0xAE, 0, 0, 0);
					keybd_event (0xAE, 0, KEYEVENTF_KEYUP, 0);
				}
				else if(key == VK_ESCAPE){
					goto main_ret;
				}
				if(b){
					if(i < 0) PlaySound(NULL, NULL, 0);
					else PlaySound(filelist[i], NULL, SND_FILENAME|SND_ASYNC);
					goto while_end;
				}
			}
		}
	while_end:;
	}
	cprintf(YELLOW, "END\n");
main_ret:
	PlaySound(NULL, NULL, 0);
	system("pause");
	return 0;
}
