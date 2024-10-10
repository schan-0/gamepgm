//main.c
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL_KEYS 88

// â ũ�� 
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 400;

int current_octave = 0;

// ���� ���� ���
const char* SOUND_PATH = "source/";

// ���� ���� ����
bool is_recording = false;
FILE* record_file = NULL;

// �ð� 
Uint32 get_current_time() {
    return SDL_GetTicks();
}

//====================================================SOUND LOADING===================================================================
Mix_Chunk* load_sound(const char* filename) {				// ogg, wav, flac �� ���� �ε�
    Mix_Chunk* sound = Mix_LoadWAV(filename);
    return sound;
}
void play_sound(Mix_Chunk* sound, int channel) {			// �Ҹ� ��� 
    if (sound) {
    	Mix_FadeOutChannel(channel, 10);
        Mix_PlayChannel(channel, sound, 0);
    }
}
//===================================================SOUND LOADING OVER==============================================================



//====================================================KEY to SOUND FILE===================================================================
void get_sound_filename(char* buffer, const char* pressed_key, int octave) {
    sprintf(buffer, "%s%s%d.ogg", SOUND_PATH, pressed_key, octave);
}
void handle_key_press(char key) {
    int key_index = -1;
    const char* pressed_key_name = NULL;
    switch (key) {															// key : key_index = $; pressed_key_name = "%s"; break; ... octave control
        case 'q': key_index = 0; pressed_key_name = "Flat_b"; break;
        case 'a': key_index = 1; pressed_key_name = "b"; break;
        case 's': key_index = 2; pressed_key_name = "c"; break;
        case 'e': key_index = 3; pressed_key_name = "Flat_d"; break;
        case 'd': key_index = 4; pressed_key_name = "d"; break;
        case 'r': key_index = 5; pressed_key_name = "Flat_e"; break;
        case 'f': key_index = 6; pressed_key_name = "e"; break;
        case 'j': key_index = 7; pressed_key_name = "f"; break;
        case 'i': key_index = 8; pressed_key_name = "Flat_g"; break;
        case 'k': key_index = 9; pressed_key_name = "g"; break;
        case 'o': key_index = 10; pressed_key_name = "Flat_a"; break;
        case 'l': key_index = 11; pressed_key_name = "a"; break;
        case 'p': key_index = 12; pressed_key_name = "Flat_b"; break;
        case ';': key_index = 13; pressed_key_name = "b"; break;
        case 'v':
            current_octave--;
            if (current_octave < -3) current_octave = -3; // �ּ� ��Ÿ�� ����
            break;
        case 'n':
            current_octave++;
            if (current_octave > 3) current_octave = 3; // �ִ� ��Ÿ�� ����
            break;
        default:
            break;
    }
    
    
	
	
    if (key_index != -1 && pressed_key_name != NULL) {						// Ű�� ���ȴٸ� ... 
        char sound_file[10];
        if (key_index <= 1)													// C ���� -1 ��Ÿ��,  gsf - ���ڸ� �ѱ�� gsf�� sound_file ���� ���� 
        	get_sound_filename(sound_file, pressed_key_name, 3 + current_octave);
        else
        	get_sound_filename(sound_file, pressed_key_name, 4 + current_octave);
        Mix_Chunk* sound = load_sound(sound_file);							// Mix_chunk[]�� ������ �ɰ� ���� ����...? ���ϸ��� ������ ���� �׷� �� ���ϵ� 
        if (sound) {
            play_sound(sound, key_index);
        }
        if (is_recording && record_file) {									// ���� Ȱ��ȭ �� Ű-Ÿ�ӽ����� ���� record_file�� ��� 
            Uint32 timestamp = get_current_time();
            fprintf(record_file, "%s %d\n", sound_file, timestamp);
        }
    }
}
//====================================================KEY to SOUND FILE OVER=============================================================





// =================================================== RECORD =====================================================================
void start_recording() {
    if (is_recording) return;
    is_recording = true;
    char filename[200];
    sprintf(filename, "rec/record_%ld.txt", get_current_time());			    // ���� �̸��� �ð� �߰�
    record_file = fopen(filename, "w");											// ������� ���� 
    if (!record_file)
        is_recording = false;	// File �ε� ���� 
}
void stop_recording() {							// ���ڵ� �� ȣ��Ǹ� ���� �ݰ� ���� ���������� NULL�� �ǵ���
    if (!is_recording) return;
    is_recording = false;
    if (record_file) {
        fclose(record_file);
        record_file = NULL;
    }
}
void toggle_recording() {
    if (is_recording)
        stop_recording();
    else
        start_recording();
}
//===================================================RECORD OVER==========================================================




void play_recording(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file)
        return;

    char key_name[20];
    int timestamp;
    Uint32 start_time = get_current_time();
    Uint32 last_time = 0;

    while (fscanf(file, "%s %d", key_name, &timestamp) != EOF) {
        Uint32 delay = timestamp - last_time;
        SDL_Delay(delay);
        last_time = timestamp;

		int channel = 0;
		switch (key_name[0]){
			case 'b': channel = 0; break;
        	case 'c': channel = 1; break;
        	case 'd': channel = 2; break;
        	case 'e': channel = 3; break;
        	case 'f': channel = 4; break;
        	case 'g': channel = 5; break;
        	case 'a': channel = 6; break;
        	case 'F': channel = 7; break;
		}
        char sound_file[10];
        sprintf(sound_file, "%s", key_name);
        Mix_Chunk* sound = load_sound(sound_file);
        if (sound)
            play_sound(sound, channel);
    }
    fclose(file);
}




int main(int argc, char* argv[]) {
    // SDL �ʱ�ȭ
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0) {
        printf("SDL �ʱ�ȭ ����: %s\n", SDL_GetError());
        return 1;
    }

    // SDL_image �ʱ�ȭ
    if (!(IMG_Init(IMG_INIT_PNG) && IMG_INIT_PNG)) {
        printf("SDL_image �ʱ�ȭ ����: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // SDL_mixer �ʱ�ȭ
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer �ʱ�ȭ ����: %s\n", Mix_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
	Mix_AllocateChannels(14);
    // â �� ������ ����
    SDL_Window* window = SDL_CreateWindow("C Piano", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("������ ���� ����: %s\n", SDL_GetError());
        Mix_CloseAudio();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("������ ���� ����: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // piano.png �ε�
    SDL_Surface* piano_surface = IMG_Load("source/piano.png");		// IMG_Load�� SDL_Surface�� return
    if (!piano_surface) {
        printf("piano.png �ε� ����: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Texture* piano_texture = SDL_CreateTextureFromSurface(renderer, piano_surface);
    SDL_FreeSurface(piano_surface);
    if (!piano_texture) {
        printf("piano_texture ���� ����: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // �ǹ� ���� ���� (������ ����, �����δ� �� �ǹ��� ��Ȯ�� ��ġ�� �����ؾ� ��)
    SDL_Rect key_rects[14]; // 14���� Ű ����
    int key_width = WINDOW_WIDTH / 14;
    int i;
    for (i = 0; i < 14; i++) {
        key_rects[i].x = i * key_width;
        key_rects[i].y = 0;
        key_rects[i].w = key_width;
        key_rects[i].h = WINDOW_HEIGHT - 50; // ��ư ���� Ȯ��
    }

    // ��ư ���� ����
    SDL_Rect record_button = { 10, WINDOW_HEIGHT - 40, 100, 30 };							// ���� 
    SDL_Rect play_button = { WINDOW_WIDTH - 110, WINDOW_HEIGHT - 40, 100, 30 };				// ������ 

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
        	
            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                	if (e.key.keysym.sym == SDLK_SPACE)
                		toggle_recording();
                	else
                    	handle_key_press(e.key.keysym.sym);
                    break;
                case SDL_MOUSEBUTTONDOWN:	//-------------------------------------------------------------------------
                    if (e.button.button == SDL_BUTTON_LEFT) {									// ���콺 ��Ŭ�� ���� �� Ŭ�� ��ġ�� ������ ����. ��ư �ȿ��� �߻��� Ŭ���̸�..?
                        int x = e.button.x;
                        int y = e.button.y;
                        // üũ record ��ư
                        if (x >= record_button.x && x <= record_button.x + record_button.w &&				// record ��ư 
                            y >= record_button.y && y <= record_button.y + record_button.h) {
                            if (!is_recording) {
                                start_recording();
                            } else {
                                stop_recording();
                            }
                        }
                        if (x >= play_button.x && x <= play_button.x + play_button.w &&						// play ��ư 
                            y >= play_button.y && y <= play_button.y + play_button.h) {
                            
                        }
                    }
                    break;//--------------------------------------------------------------------------------------------
                default:
                    break;
            }
        }
        // ������
        SDL_RenderClear(renderer);

        // piano �ؽ�ó
        SDL_RenderCopy(renderer, piano_texture, NULL, NULL);
		
        // ���� ON/OFF ���� 
        if (is_recording) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // R
            SDL_RenderFillRect(renderer, &record_button);
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // W
            SDL_RenderFillRect(renderer, &record_button);
        }

        // ��� ��ư
        SDL_SetRenderDrawColor(renderer, 124, 124, 124, 255);
        SDL_RenderFillRect(renderer, &play_button);
        
		// ��ư ��輱
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &record_button);
        SDL_RenderDrawRect(renderer, &play_button);
        
        

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(piano_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

