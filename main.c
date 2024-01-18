/*
--------------------------------------------------
    James William Fletcher (github.com/mrbid)
        July 2023
--------------------------------------------------
    C & SDL / OpenGL ES2 / GLSL ES
    Colour Converter: https://www.easyrgb.com

    VoxelPainter
    https://github.com/mrbid/voxelpaint
*/

#pragma GCC diagnostic ignored "-Wtrigraphs"

const unsigned char icon[] = { // 16, 16, 4
"\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\000(!\"\003$\"\"\377\377\377\000\377\377\377\000\377\377"
  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\000\000\000\021\000JI\063\000\225\230f\035nw\252l?V\335"
  "y\066X\335\064Xv\252\000\215\220w\000b[\063\000\015\007\021\377\377\377\000\377\377\377"
  "\000\377\377\377\000\377\377\377\000\012EGD\061DJ\210r\040$\314}ip\377\063\231\231"
  "\377i]]\377\330\\@\377\315\222\063\377M\234T\377\060\232\245\377\206js\377"
  "w$(\314\065TZ\231\027`aU\000\000\000\021\015\020\020\063\071\234\235\356O\310\313\377\217"
  "io\377\212\254\264\377\062\247\266\377mY\070\377\247\244$\377j\271%\377$\224"
  "I\377.\266\307\377\212\254\264\377\213pu\377R\321\314\377>\236\225\356\015"
  "\020\020\063\003?@\"Qee\356\207[\\\377A\265\265\377\017\342\344\377?\330\336\377"
  "\\\250\255\377\274SZ\377\264Vi\377^\261\277\377G\332\330\377\015\347\334\377"
  "I\261\246\377\226NI\377Zd\\\356\003C=\063\000\206\205\021\\BC\335\367&(\377\\\264"
  "\265\377\024\343\344\377d\202\207\377H\307\310\377Y\325\326\377Z\336\326\377"
  "O\265\253\377d\201w\377\013\354\326\377l\263\246\377\377-,\377lKF\335\000jb"
  "\"\000\015\007\021;gg\314\232\203\206\377Z^Z\377\013\237\237\377\242il\377\275\021"
  "\025\377M\312\305\377X\252\236\377\315\013\013\377\222ul\377\012\230\212\377"
  "aXN\377\240\215\203\377>pi\314\000\015\007\021\000\000\000\021\013\237\237\273\021\271\266"
  "\377\207\012\005\377\213\002\006\377\216`d\377\376\070;\377]\244\240\377j\205}\377"
  "\377C@\377\201XS\377\231\000\000\377\217\014\002\377\023\271\246\377\006\256\243\314"
  "\000\000\000\021\377\377\377\000)}\204\252\022\252\255\377\242\224\027\377\377z\036\377"
  "\177\065'\377ifj\377f\231\231\377j\220\206\377^ca\377\211\063\037\377\377\204"
  "\035\377\255\226\023\377\037\251\240\377\064\210\202\273\000\000\000\021\377\377\377"
  "\000\070?C\231\213]i\377P\214'\377\240\364\002\377\225\221\023\377\007\256\277\377"
  "=\277\303\377<\312\276\377\006\250\247\377\234\222\012\377\244\371\002\377P\211"
  "%\377\232]d\377IHD\252\377\377\377\000\377\377\377\000\034OM\210\327HM\377\215"
  "Wb\377\000z\031\377\060]\020\377*\265\274\377\014\357\356\377\015\357\340\377'\263"
  "\240\377)_\006\377\000z\031\377xWY\377\353IG\377\061[R\252\377\377\377\000\377\377"
  "\377\000\006KLUSXW\356x\200\205\377\015\277\315\377ds~\377\267kl\377R\233\232"
  "\377R\226\214\377\277lc\377tyx\377\013\302\300\377j\205}\377[XQ\377\024XPw"
  "\377\377\377\000\377\377\377\000\377\377\377\000\000&&\063']\\\252\021\272\271\377"
  "o\227\232\377\370\024\027\377k\201\200\377lyr\377\377\025\025\377\203\230\217"
  "\377\021\277\260\377+e^\273\000&&D\377\377\377\000\377\377\377\000\377\377\377\000"
  "\377\377\377\000\377\377\377\000\377\377\377\000\000\063\063U']\\\273`GI\377j\271\267"
  "\377m\270\253\377lKF\377._W\314\000\063\063U\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
  "\377\000\377\377\377\000\000\000\000\021\000ffU:\214\211\314\071\220\206\314\000jbf\000\000\000"
  "\021\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\000\000\000\021\000\006\007\"\377\377\377\000\377\377\377\000\377"
  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000",
};

//#define SKYBLUE
//#define NO_COMPRESSION
//#define VERBOSE

#include <time.h>
#ifndef NO_COMPRESSION
    #include <zlib.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

#ifdef __linux__
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <locale.h>
#endif

#include "inc/esVoxel.h"

#define uint GLuint
#define sint GLint
#define uchar unsigned char
#define forceinline __attribute__((always_inline)) inline

//*************************************
// globals
//*************************************
const char appTitle[] = "Voxel Paint";
const char appVersion[] = "v2.3";
char *basedir, *appdir;
SDL_Window* wnd;
SDL_GLContext glc;
SDL_Surface* s_icon = NULL;
int winw = 1024, winh = 768;
int winw2 = 512, winh2 = 384;
float ww, wh;
float aspect, t = 0.f;
uint maxed=0,size=0,dsx=0,dsy=0;
int mx=0, my=0, xd=0, yd=0, md=0;
uint g_fps = 0;
uint ks[10] = {0};      // keystate
uint focus_mouse = 0;   // mouse lock
float ddist = 512.f;    // view distance
float ddist2 = 512.f*512.f;
vec ipp;                // inverse player position
vec look_dir;           // camera look direction
int lray = 0;           // pointed at node index
float ptt = 0.f;        // place timing trigger (for repeat place)
float dtt = 0.f;        // delete timing trigger (for repeat delete)
uint fks = 0;           // F-Key state (fast mode toggle)
uint ise = 0;           // is selecting
vec sp1d, sp1, sp2, sdif, sdifo, sp1o; // selecting vars
float bigc = 0.f; // big cursor start time

//*************************************
// utility functions
//*************************************
void timestamp(char* ts){const time_t tt = time(0);strftime(ts, 16, "%H:%M:%S", localtime(&tt));}
forceinline float fTime(){return ((float)SDL_GetTicks())*0.001f;}
#ifdef __linux__
    uint64_t microtime()
    {
        struct timeval tv;
        struct timezone tz;
        memset(&tz, 0, sizeof(struct timezone));
        gettimeofday(&tv, &tz);
        return 1000000 * tv.tv_sec + tv.tv_usec;
    }
    uint dirExist(const char* dir)
    {
        struct stat st;
        return (stat(dir, &st) == 0 && S_ISDIR(st.st_mode));
    }
    uint fileExist(const char* file)
    {
        struct stat st;
        return (stat(file, &st) == 0);
    }
#endif
static SDL_HitTestResult SDLCALL hitTest(SDL_Window *window, const SDL_Point *pt, void *data)
{
    if(focus_mouse == 1){return SDL_HITTEST_NORMAL;}
    if( SDL_PointInRect(pt, &(SDL_Rect){40, 0, winw2-85, 22}) == SDL_TRUE ||
        SDL_PointInRect(pt, &(SDL_Rect){winw2+60, 0, winw2-102, 22}) == SDL_TRUE)
        return SDL_HITTEST_DRAGGABLE;
    return SDL_HITTEST_NORMAL;
}

//*************************************
// game state functions
//*************************************

// game data (for fast save and load)
#define max_voxels 4194304 // 4.2 million
#define header_size 68
#define max_data_size 67108932 // (max_voxels*sizeof(vec)) + header_size
typedef struct
{
    vec pp;     // player position
    vec pb;     // place block pos
    float sens; // mouse sensitivity
    float xrot; // camera x-axis rotation
    float yrot; // camera y-axis rotation
    float st;   // selected texture
    float ms;   // player move speed
    float cms;  // custom move speed (high)
    float lms;  // custom move speed (low)
    uchar grav; // gravity on/off toggle
    uchar plock;// pitchlock on/off toggle
    uchar r1, r2;
    uint num_voxels;
    vec voxels[max_voxels]; // x,y,z,w (w = texture_id)
}
game_state;
game_state g; // ~67mb

int swapfunc(const void *a, const void *b)
{
    const float aw = ((vec*)a)->w;
    const float bw = ((vec*)b)->w;
    if(aw == bw){return 0;}
    else if(aw == -1.f){return 1;}
    return 0;
}
void optimState()
{
    qsort(g.voxels, g.num_voxels, sizeof(vec), swapfunc);
    for(uint i = 0; i < g.num_voxels; i++)
    {
        if(g.voxels[i].w == -1.f)
        {
            g.num_voxels = i;
            break;
        }
    }
}

void defaultState(const uint type)
{
    g.sens = 0.003f;
    g.xrot = 0.f;
    g.yrot = 1.5f;
    g.pp = (vec){0.f, 4.f, 0.f};
    if(type == 0)
    {
        g.ms = 9.3f;
    }
    g.st = 10.f;
    g.pb = (vec){0.f, 0.f, 0.f, -1.f};
    if(type == 0)
    {
        g.lms = g.ms;
        g.cms = g.ms*2.f;
    }
    g.grav = 0;
    g.plock = 0;
    if(g.num_voxels == 0){g.num_voxels = 1;}
}

// load old state file (to save as new state file)
typedef struct {
    uint num_voxels;
    vec voxels[max_voxels];
    float sens, xrot, yrot;
    vec look_dir, pp;
    float ms;
    vec pb;
    float st, cms, lms;
    uint grav;
}old_game_state;
old_game_state og;
uint loadOldState()
{
    char file[256];
    sprintf(file, "%sworld.db", appdir);
    FILE* f = fopen(file, "rb");
    if(f != NULL)
    {
        if(fread(&og, 1, sizeof(old_game_state), f) != sizeof(old_game_state))
        {
            char tmp[16];
            timestamp(tmp);
            printf("[%s] world.db was of an unexpected size.\n", tmp);
        }
        fclose(f);
        fks = (og.ms == og.cms); // update F-Key State
        g.num_voxels = og.num_voxels;
        memcpy(g.voxels, og.voxels, og.num_voxels*sizeof(vec));
        g.sens = og.sens;
        g.xrot = og.xrot;
        g.yrot = og.yrot;
        g.pp = og.pp;
        g.ms = og.ms;
        g.pb = og.pb;
        g.st = og.st;
        g.cms = og.cms;
        g.lms = og.lms;
        g.grav = og.grav;
        char tmp[16];
        timestamp(tmp);
        printf("[%s] Loaded old world.db file %u voxels.\n", tmp, g.num_voxels);
        return 1;
    }
    return 0;
}

uint loadUncompressedState()
{
#ifdef __linux__
    setlocale(LC_NUMERIC, "");
    const uint64_t st = microtime();
#endif
    char file[256];
    sprintf(file, "%sworld.db2", appdir);
    FILE* f = fopen(file, "rb");
    if(f != NULL)
    {
        fseek(f, 0, SEEK_END);
        long rs = ftell(f);
        fseek(f, 0, SEEK_SET);
        if(fread(&g, 1, rs, f) != rs)
        {
            char tmp[16];
            timestamp(tmp);
            printf("[%s] fread() was of an unexpected size.\n", tmp);
        }
        fclose(f);
        fks = (g.ms == g.cms); // update F-Key State
        char tmp[16];
        timestamp(tmp);
#ifndef __linux__
        printf("[%s] Loaded %u voxels.\n", tmp, g.num_voxels);
#else
        printf("[%s] Loaded %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
#endif
        return 1;
    }
    return 0;
}

#ifdef NO_COMPRESSION
    void saveState(const char* fne)
    {
        optimState();
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.db2%s", appdir, fne);
        FILE* f = fopen(file, "wb");
        if(f != NULL)
        {
            const size_t ws = header_size + (g.num_voxels*sizeof(vec));
            if(fwrite(&g, 1, ws, f) != ws)
            {
                char tmp[16];
                timestamp(tmp);
                printf("[%s] Save corrupted.\n", tmp);
            }
            fclose(f);
            char tmp[16];
            timestamp(tmp);
    #ifndef __linux__
            printf("[%s] Saved %u voxels.\n", tmp, g.num_voxels);
    #else
            printf("[%s] Saved %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
    #endif
        }
    }

    uint loadState(){return loadUncompressedState();}
#else
    void saveState(const char* fne)
    {
        optimState();
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.gz%s", appdir, fne);
        gzFile f = gzopen(file, "wb1h");
        if(f != Z_NULL)
        {
            const size_t ws = header_size + (g.num_voxels*sizeof(vec));
            if(gzwrite(f, &g, ws) != ws)
            {
                char tmp[16];
                timestamp(tmp);
                printf("[%s] Save corrupted.\n", tmp);
            }
            gzclose(f);
            char tmp[16];
            timestamp(tmp);
    #ifndef __linux__
            printf("[%s] Saved %'u voxels.\n", tmp, g.num_voxels);
    #else
            printf("[%s] Saved %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
    #endif
        }
    }

    uint loadState()
    {
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.gz", appdir);
        gzFile f = gzopen(file, "rb");
        if(f != Z_NULL)
        {
            int gr = gzread(f, &g, max_data_size);
            gzclose(f);
            fks = (g.ms == g.cms); // update F-Key State
            char tmp[16];
            timestamp(tmp);
    #ifndef __linux__
            printf("[%s] Loaded %u voxels\n", tmp, g.num_voxels);
    #else
            printf("[%s] Loaded %'u voxels. (%'lu μs)\n", tmp, g.num_voxels, microtime()-st);
    #endif
            return 1;
        }
        return 0;
    }
#endif

//*************************************
// ray & render functions
//*************************************

// render state id's
GLint projection_id;
GLint view_id;
GLint voxel_id;
GLint position_id;
GLint normal_id;
GLint texcoord_id;
GLint sampler_id;

// render state matrices
mat projection;
mat view;

// hit_vec will be untouched by this if there's no collision (function by hax/test_user)
#define RAY_DEPTH 70
int ray(vec *hit_vec, const uint depth, const vec vec_start_pos)
{
	int hit = -1;
	float bestdist;
	float start_pos[] = {vec_start_pos.x, vec_start_pos.y, vec_start_pos.z};
	float lookdir[] = {look_dir.x, look_dir.y, look_dir.z};
	for (int i = 0; i < g.num_voxels; i++)
    {
		if(g.voxels[i].w < 0.f){continue;}
		float offset[] = {g.voxels[i].x - start_pos[0], g.voxels[i].y - start_pos[1], g.voxels[i].z - start_pos[2]};
		int j = 0;
        // hmmmmmm... is there some decent way to get around this...
		float max = fabsf(offset[0]);
		float tmp = fabsf(offset[1]);
		if(tmp > max){max = tmp; j = 1;}
		tmp = fabsf(offset[2]);
		if(tmp > max){max = tmp; j = 2;}
		if (max <= 0.5f) { // unlikely but better than breaking... costs some cycles though
			*hit_vec = vec_start_pos;
			return i;
		}
		float dist_to_start = offset[j];
		if(dist_to_start > 0.f){dist_to_start -= 0.5f;}else{dist_to_start += 0.5f;}
		const float multiplier = dist_to_start / lookdir[j];
        // too far out (or not in the right direction), don't bother
		if(multiplier > depth || (hit != -1 && multiplier > bestdist) || multiplier < 0.f){continue;}
        // Might end up taking all 222 of those cycles below... :/
        // At least better than what it was originally though
        // And with enough out of range there's still a chance average comes out under
		{
			float pos[] = {start_pos[0] + (lookdir[0] * multiplier), start_pos[1] + (lookdir[1] * multiplier), start_pos[2] + (lookdir[2] * multiplier)};
			if (pos[0] > g.voxels[i].x + 1.5f || pos[0] < g.voxels[i].x - 1.5f ||
				pos[1] > g.voxels[i].y + 1.5f || pos[1] < g.voxels[i].y - 1.5f ||
				pos[2] > g.voxels[i].z + 1.5f || pos[2] < g.voxels[i].z - 1.5f) {continue;} // not even a chance of hitting
            ///
			if ((j == 0 || (pos[0] >= g.voxels[i].x - 0.5f && pos[0] <= g.voxels[i].x + 0.5f)) && // j == n so float inaccuracies won't proceed to tell me that it's out after I just put it on the edge
				(j == 1 || (pos[1] >= g.voxels[i].y - 0.5f && pos[1] <= g.voxels[i].y + 0.5f)) &&
				(j == 2 || (pos[2] >= g.voxels[i].z - 0.5f && pos[2] <= g.voxels[i].z + 0.5f))) { // hit
				hit = i;
				float sign;
				if(offset[j] > 0.f){sign = -1.f;}else{sign = 1.f;}
				if(j == 0){hit_vec->x = sign;}else{hit_vec->x = 0.f;}
				if(j == 1){hit_vec->y = sign;}else{hit_vec->y = 0.f;}
				if(j == 2){hit_vec->z = sign;}else{hit_vec->z = 0.f;}
				bestdist = multiplier;
				continue; // no need to check side cases :P
			}
		}
        ///
		float first_dist;
		char first_dir;
		float second_dist;
		char second_dir;
		for (int n = 0, y = 0; n <= 2; n++)
        {
			if (n != j)
            {
				float dist;
				if(offset[n] > 0){dist = offset[n] - 0.5f;}else{dist = offset[n] + 0.5f;}
				dist = dist / lookdir[n];
				if (y == 0) {
					first_dist = dist;
					first_dir = n;
				} else {
					if (dist < first_dist) {
						second_dist = first_dist;
						second_dir = first_dir;
						first_dist = dist;
						first_dir = n;
					} else {
						second_dist = dist;
						second_dir = n;
					}
				}
				y++;
			}
		}
        ///
		{
			if(first_dist > depth || (hit != -1 && first_dist > bestdist)){continue;}
			float pos[] = {start_pos[0] + (lookdir[0] * first_dist), start_pos[1] + (lookdir[1] * first_dist), start_pos[2] + (lookdir[2] * first_dist)};
			if ((first_dir == 0 || (pos[0] >= g.voxels[i].x - 0.5f && pos[0] <= g.voxels[i].x + 0.5f)) &&
				(first_dir == 1 || (pos[1] >= g.voxels[i].y - 0.5f && pos[1] <= g.voxels[i].y + 0.5f)) &&
				(first_dir == 2 || (pos[2] >= g.voxels[i].z - 0.5f && pos[2] <= g.voxels[i].z + 0.5f)))
            {
				hit = i;
				float sign;
				if(offset[first_dir] > 0.f){sign = -1.f;}else{sign = 1.f;}
				if(first_dir == 0){hit_vec->x = sign;}else{hit_vec->x = 0.f;}
				if(first_dir == 1){hit_vec->y = sign;}else{hit_vec->y = 0.f;}
				if(first_dir == 2){hit_vec->z = sign;}else{hit_vec->z = 0.f;}
				bestdist = first_dist;
				continue;
			}
		}
        ///
		{
			if (second_dist > depth || (hit != -1 && second_dist > bestdist)){continue;}
			float pos[] = {start_pos[0] + (lookdir[0] * second_dist), start_pos[1] + (lookdir[1] * second_dist), start_pos[2] + (lookdir[2] * second_dist)};
			if ((second_dir == 0 || (pos[0] >= g.voxels[i].x - 0.5f && pos[0] <= g.voxels[i].x + 0.5f)) &&
				(second_dir == 1 || (pos[1] >= g.voxels[i].y - 0.5f && pos[1] <= g.voxels[i].y + 0.5f)) &&
				(second_dir == 2 || (pos[2] >= g.voxels[i].z - 0.5f && pos[2] <= g.voxels[i].z + 0.5f)))
            {
				hit = i;
				float sign;
				if(offset[second_dir] > 0.f){sign = -1.f;}else{sign = 1.f;}
				if(second_dir == 0){hit_vec->x = sign;}else{hit_vec->x = 0.f;}
				if(second_dir == 1){hit_vec->y = sign;}else{hit_vec->y = 0.f;}
				if(second_dir == 2){hit_vec->z = sign;}else{hit_vec->z = 0.f;}
				bestdist = second_dist;
				continue;
			}
		}
	}
	return hit;
}
void traceViewPath(const uint face)
{
    g.pb.w = -1.f;
    vec rp = g.pb;
    lray = ray(&rp, RAY_DEPTH, ipp);
    if(lray > -1 && face == 1)
    {
        rp.x += g.voxels[lray].x;
        rp.y += g.voxels[lray].y;
        rp.z += g.voxels[lray].z;
        uint rpif = 1;
        for(int i = 0; i < g.num_voxels; i++)
        {
            if(g.voxels[i].w < 0.f){continue;}
            if(rp.x == g.voxels[i].x && rp.y == g.voxels[i].y && rp.z == g.voxels[i].z)
            {
                rpif = 0;
                break;
            }
        }
        if(rpif == 1)
        {
            g.pb   = rp;
            g.pb.w = 1.f;
        }
    }
}

// #define RAY_DEPTH 300
// #define RAY_STEP 0.125f
// // shoot ray through voxels (returns voxel index and hit vector)
// int ray(vec* hit_vec, const uint depth, const float stepsize, const vec start_pos)
// {
//     vec inc;
//     vMulS(&inc, look_dir, stepsize);
//     int hit = -1;
//     vec rp = start_pos;
//     for(uint i = 0; i < depth; i++)
//     {
//         vAdd(&rp, rp, inc);
//         vec rb;
//         rb.x = roundf(rp.x);
//         rb.y = roundf(rp.y);
//         rb.z = roundf(rp.z);
//         for(int j = 0; j < g.num_voxels; j++)
//         {
//             if(g.voxels[j].w < 0.f){continue;}
//             if(rb.x == g.voxels[j].x && rb.y == g.voxels[j].y && rb.z == g.voxels[j].z)
//             {
//                 *hit_vec = (vec){rp.x-rb.x, rp.y-rb.y, rp.z-rb.z};
//                 hit = j;
//                 break;
//             }
//         }
//         if(hit > -1){break;}
//     }
//     return hit;
// }
// void traceViewPath(const uint face)
// {
//     g.pb.w = -1.f;
//     vec rp = g.pb;
//     lray = ray(&rp, RAY_DEPTH, RAY_STEP, ipp);
//     if(lray > -1 && face == 1)
//     {
//         vNorm(&rp);
//         vec diff = rp;
//         rp = g.voxels[lray];

//         vec fd = diff;
//         fd.x = fabsf(diff.x);
//         fd.y = fabsf(diff.y);
//         fd.z = fabsf(diff.z);
//         if(fd.x > fd.y && fd.x > fd.z)
//         {
//             diff.y = 0.f;
//             diff.z = 0.f;
//         }
//         else if(fd.y > fd.x && fd.y > fd.z)
//         {
//             diff.x = 0.f;
//             diff.z = 0.f;
//         }
//         else if(fd.z > fd.x && fd.z > fd.y)
//         {
//             diff.x = 0.f;
//             diff.y = 0.f;
//         }
//         diff.x = roundf(diff.x);
//         diff.y = roundf(diff.y);
//         diff.z = roundf(diff.z);

//         rp.x += diff.x;
//         rp.y += diff.y;
//         rp.z += diff.z;

//         if(vSumAbs(diff) == 1.f)
//         {
//             uint rpif = 1;
//             for(int i = 0; i < g.num_voxels; i++)
//             {
//                 if(g.voxels[i].w < 0.f){continue;}

//                 if(rp.x == g.voxels[i].x && rp.y == g.voxels[i].y && rp.z == g.voxels[i].z)
//                 {
//                     rpif = 0;
//                     break;
//                 }
//             }
//             if(rpif == 1)
//             {
//                 g.pb   = rp;
//                 g.pb.w = 1.f;
//             }
//         }
//     }
// }

int placeVoxel(const float repeat_delay)
{
    ptt = t+repeat_delay;

    if(g.pb.w == -1){return -1;} // place block invalid texture (failed ray indication)

    for(uint i = 256; i < g.num_voxels; i++)
    {
        if(g.voxels[i].w < 0.f)
        {
            g.voxels[i] = g.pb;
            g.voxels[i].w = g.st;
            return i;
        }
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = g.pb;
        g.voxels[g.num_voxels].w = g.st;
        const int r = g.num_voxels;
        g.num_voxels++;
        return r;
    }
    return -2; // no space left
}
int placeVoxelArb(const vec v)
{
    uint free = -1;
    for(uint i = 256; i < g.num_voxels; i++)
    {
        if(free == -1 && g.voxels[i].w < 0.f){free = i;} // find first free slot (pre-emptive)
        if(g.voxels[i].x == v.x && g.voxels[i].y == v.y && g.voxels[i].z == v.z){return -1;} // already exists
    }
    if(free != -1)
    {
        g.voxels[free] = v;
        return free;
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = v;
        const int r = g.num_voxels;
        g.num_voxels++;
        return r;
    }
    return -2; // no space left
}
int forceVoxelArb(const vec v)
{
    uint free = -1;
    for(uint i = 256; i < g.num_voxels; i++)
    {
        if(free == -1 && g.voxels[i].w < 0.f){free = i;} // find first free slot (pre-emptive)
        if(g.voxels[i].x == v.x && g.voxels[i].y == v.y && g.voxels[i].z == v.z){free = i;break;} // already exists
    }
    if(free != -1)
    {
        g.voxels[free] = v;
        return free;
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = v;
        const int r = g.num_voxels;
        g.num_voxels++;
        return r;
    }
    return -2; // no space left
}
// forceinline int findVoxel(const float x, const float y, const float z)
// {
//     for(uint i = 0; i < g.num_voxels; i++)
//     {
//         if(g.voxels[i].x == x && g.voxels[i].y == y && g.voxels[i].z == z)
//             return i;
//     }
//     return -1;
// }

//*************************************
// more utility functions
//*************************************
void printAttrib(SDL_GLattr attr, char* name)
{
    int i;
    SDL_GL_GetAttribute(attr, &i);
    printf("%s: %i\n", name, i);
}
SDL_Surface* SDL_RGBA32Surface(Uint32 w, Uint32 h)
{
    return SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
}
void drawHud();
void doPerspective()
{
    glViewport(0, 0, winw, winh);
    if(winw > 500 && winh > 280)
    {
        SDL_FreeSurface(sHud);
        sHud = SDL_RGBA32Surface(winw, winh);
        drawHud();
        hudmap = esLoadTextureA(winw, winh, sHud->pixels, 0);
    }
    ww = (float)winw;
    wh = (float)winh;
    mIdent(&projection);
    mPerspective(&projection, 60.0f, ww / wh, 0.1f, ddist);
    glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);
}
forceinline uint insideFrustum(const float x, const float y, const float z)
{
    const float xm = x+g.pp.x, ym = y+g.pp.y, zm = z+g.pp.z;
    return (xm*look_dir.x) + (ym*look_dir.y) + (zm*look_dir.z) > 0.f; // check the angle
}
SDL_Surface* surfaceFromData(const Uint32* data, Uint32 w, Uint32 h)
{
    SDL_Surface* s = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
    memcpy(s->pixels, data, s->pitch*h);
    return s;
}
forceinline Uint32 getpixel(const SDL_Surface *surface, Uint32 x, Uint32 y)
{
    const Uint8 *p = (Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel;
    return *(Uint32*)p;
}
forceinline void setpixel(SDL_Surface *surface, Uint32 x, Uint32 y, Uint32 pix)
{
    const Uint8* pixel = (Uint8*)surface->pixels + (y * surface->pitch) + (x * surface->format->BytesPerPixel);
    *((Uint32*)pixel) = pix;
}
void replaceColour(SDL_Surface* surf, SDL_Rect r, Uint32 old_color, Uint32 new_color)
{
    const Uint32 max_y = r.y+r.h;
    const Uint32 max_x = r.x+r.w;
    for(Uint32 y = r.y; y < max_y; ++y)
        for(Uint32 x = r.x; x < max_x; ++x)
            if(getpixel(surf, x, y) == old_color){setpixel(surf, x, y, new_color);}
}

//*************************************
// Simple Font
//*************************************
int drawText(SDL_Surface* o, const char* s, Uint32 x, Uint32 y, Uint8 colour)
{    
    static const Uint8 font_map[] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,255,255,255,0,0,0,0,255,255,255,0,255,0,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,0,255,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,0,0,255,0,0,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,0,255,255,0,0,0,0,0,255,0,0,0,0,255,0,0,0,0,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,255,255,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,255,0,0,255,0,0,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,255,255,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,255,255,0,0,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,0,0,0,0,0,255,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,255,255,255,255,0,255,255,255,255,255,255,255,255,0,0,255,0,0,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,255,255,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,0,0,255,255,0,0,255,255,255,0,0,0,0,255,0,0,0,0,0,0,0,0,255,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,255,255,0,0,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,0,0,0,255,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,255,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,255,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,0,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,255,0,0,255,255,255,255,0,0,255,255,0,0,0,255,255,0,0,255,255,255,0,0,255,255,255,255,255,255,255,0,0,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,0,255,255,255,255,255,255,255,255,0,0,255,0,0,255,0,0,0,0,0,255,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,0,0,0,0,0,0,0,255,0,0,255,255,255,255,0,0,0,0,0,255,255,255,0,0,255,255,255,0,255,0,0,0,0,255,0,0,0,255,0,0,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,0,0,0,255,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,0,0,255,255,0,0,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,0,255,255,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,255,0,0,255,255,255,255,0,0,255,255,255,0,0,0,255,255,0,255,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,255,255,255,0,0,255,255,0,0,0,0,255,0,0,255,255,0,0,0,0,255,255,255,255,255,0,255,255,255,255,255,255,255,255,0,0,255,0,0,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,255,255,0,0,0,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,0,255,255,255,0,0,255,255,255,0,255,255,0,0,255,255,0,0,0,255,255,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,255,0,0,255,255,255,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,0,0,255,255,255,255,0,0,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,255,255,0,0,255,255,0,0,255,0,0,0,0,255,0,0,255,0,0,255,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,0,0,255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,255,255,255,0,0,0,255,255,0,0,255,255,255,255,255,0,0,0,0,255,255,0,0,255,255,255,0,0,255,0,0,255,255,0,0,255,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,0,0,255,255,0,0,255,255,255,0,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,255,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,0,0,255,255,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,0,0,255,255,0,0,0,255,255,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,0,0,0,0,255,255,0,0,255,255,0,0,255,0,0,0,0,255,0,0,0,0,0,0,0,0,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,0,0,255,255,0,0,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,255,0,0,255,255,255,255,255,255,255,0,255,255,255,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,0,0,255,255,255,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,255,0,0,255,0,0,255,255,255,255,0,0,0,0,255,0,0,255,0,0,255,255,255,0,255,255,255,255,255,255,0,0,0,255,255,255,255,0,0,0,255,255,255,0,0,0,0,255,255,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,255,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,0,0,255,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,0,0,255,0,0,255,255,255,255,0,0,255,255,0,0,255,255,255,0,0,255,0,0,255,255,0,0,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,255,255,0,0,0,0,0,0,255,255,255,0,255,255,255,255,255,255,255,0,0,255,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,255,0,0,255,255,0,0,0,0,0,0,0,0,255,255,255,255,255,255,0,0,0,255,255,255,255,0,255,0,0,0,0,0,255,0,0,255,255,255,255,255,0,0,0,0,0,255,0,0,255,255,255,0,0,0,0,0,0,0,255,255,255,0,0,255,255,255,0,0,0,0,0,255,255,255,0,0,255,255,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,0,255,0,0,0,0,0,0,0,255,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,255,0,0,0,0,0,0,255,255,0,0,255,255,0,0,0,0,255,255,0,0,255,0,0,0,0,255,0,0,0,0,0,255,255,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,0,0,0,255,0,0,0,0,0,255,255,0,0,255,255,255,0,0,255,255,0,0,255,0,0,255,255,0,0,255,255,0,0,255,255,0,0,0,0,0,255,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,255,255,255,255,0,0,255,255,0,0,0,0,255,255,0,0,0,0,255,255,255,0,0,255,255,255,0,0,0,0,255,255,0,0,0,0,255,0,0,0,0,255,255,255,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
    static const Uint32 m = 1;
    static SDL_Surface* font_black = NULL;
    static SDL_Surface* font_white = NULL;
    static SDL_Surface* font_aqua = NULL;
    static SDL_Surface* font_gold = NULL;
    static SDL_Surface* font_cia = NULL;
    if(font_black == NULL)
    {
        font_black = SDL_RGBA32Surface(380, 11);
        for(int y = 0; y < font_black->h; y++)
        {
            for(int x = 0; x < font_black->w; x++)
            {
                const Uint8 c = font_map[(y*font_black->w)+x];
                setpixel(font_black, x, y, SDL_MapRGBA(font_black->format, c, c, c, 255-c));
            }
        }
        font_white = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_white, &font_white->clip_rect);
        replaceColour(font_white, font_white->clip_rect, 0xFF000000, 0xFFFFFFFF);
        font_aqua = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_aqua, &font_aqua->clip_rect);
        replaceColour(font_aqua, font_aqua->clip_rect, 0xFF000000, 0xFFFFFF00);
        font_gold = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_gold, &font_gold->clip_rect);
        replaceColour(font_gold, font_gold->clip_rect, 0xFF000000, 0xFF00BFFF);
        font_cia = SDL_RGBA32Surface(380, 11);
        SDL_BlitSurface(font_black, &font_black->clip_rect, font_cia, &font_cia->clip_rect);
        replaceColour(font_cia, font_cia->clip_rect, 0xFF000000, 0xFF97C920);
        // #20c997(0xFF97C920) #00FF41(0xFF41FF00) #61d97c(0xFF7CD961) #51d4e9(0xFFE9D451)
    }
    if(s[0] == '*' && s[1] == 'K') // signal cleanup
    {
        SDL_FreeSurface(font_black);
        SDL_FreeSurface(font_white);
        SDL_FreeSurface(font_aqua);
        SDL_FreeSurface(font_gold);
        SDL_FreeSurface(font_cia);
        font_black = NULL;
        return 0;
    }
    SDL_Surface* font = font_black;
    if(     colour == 1){font = font_white;}
    else if(colour == 2){font = font_aqua;}
    else if(colour == 3){font = font_gold;}
    else if(colour == 4){font = font_cia;}
    SDL_Rect dr = {x, y, 0, 0};
    const Uint32 len = strlen(s);
    for(Uint32 i = 0; i < len; i++)
    {
             if(s[i] == 'A'){SDL_BlitSurface(font, &(SDL_Rect){0,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'B'){SDL_BlitSurface(font, &(SDL_Rect){7,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'C'){SDL_BlitSurface(font, &(SDL_Rect){13,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'D'){SDL_BlitSurface(font, &(SDL_Rect){19,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'E'){SDL_BlitSurface(font, &(SDL_Rect){26,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'F'){SDL_BlitSurface(font, &(SDL_Rect){31,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'G'){SDL_BlitSurface(font, &(SDL_Rect){36,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'H'){SDL_BlitSurface(font, &(SDL_Rect){43,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'I'){SDL_BlitSurface(font, &(SDL_Rect){50,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == 'J'){SDL_BlitSurface(font, &(SDL_Rect){54,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'K'){SDL_BlitSurface(font, &(SDL_Rect){59,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'L'){SDL_BlitSurface(font, &(SDL_Rect){65,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'M'){SDL_BlitSurface(font, &(SDL_Rect){70,0,9,9}, o, &dr); dr.x += 9+m;}
        else if(s[i] == 'N'){SDL_BlitSurface(font, &(SDL_Rect){79,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'O'){SDL_BlitSurface(font, &(SDL_Rect){85,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'P'){SDL_BlitSurface(font, &(SDL_Rect){92,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'Q'){SDL_BlitSurface(font, &(SDL_Rect){98,0,7,11}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'R'){SDL_BlitSurface(font, &(SDL_Rect){105,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'S'){SDL_BlitSurface(font, &(SDL_Rect){112,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'T'){SDL_BlitSurface(font, &(SDL_Rect){118,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'U'){SDL_BlitSurface(font, &(SDL_Rect){124,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == 'V'){SDL_BlitSurface(font, &(SDL_Rect){131,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'W'){SDL_BlitSurface(font, &(SDL_Rect){137,0,10,9}, o, &dr); dr.x += 10+m;}
        else if(s[i] == 'X'){SDL_BlitSurface(font, &(SDL_Rect){147,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'Y'){SDL_BlitSurface(font, &(SDL_Rect){153,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'Z'){SDL_BlitSurface(font, &(SDL_Rect){159,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'a'){SDL_BlitSurface(font, &(SDL_Rect){165,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'b'){SDL_BlitSurface(font, &(SDL_Rect){171,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'c'){SDL_BlitSurface(font, &(SDL_Rect){177,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 'd'){SDL_BlitSurface(font, &(SDL_Rect){182,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'e'){SDL_BlitSurface(font, &(SDL_Rect){188,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'f'){SDL_BlitSurface(font, &(SDL_Rect){194,0,4,9}, o, &dr); dr.x += 3+m;}
        else if(s[i] == 'g'){SDL_BlitSurface(font, &(SDL_Rect){198,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'h'){SDL_BlitSurface(font, &(SDL_Rect){204,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'i'){SDL_BlitSurface(font, &(SDL_Rect){210,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == 'j'){SDL_BlitSurface(font, &(SDL_Rect){212,0,3,11}, o, &dr); dr.x += 3+m;}
        else if(s[i] == 'k'){SDL_BlitSurface(font, &(SDL_Rect){215,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'l'){SDL_BlitSurface(font, &(SDL_Rect){221,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == 'm'){SDL_BlitSurface(font, &(SDL_Rect){223,0,10,9}, o, &dr); dr.x += 10+m;}
        else if(s[i] == 'n'){SDL_BlitSurface(font, &(SDL_Rect){233,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'o'){SDL_BlitSurface(font, &(SDL_Rect){239,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'p'){SDL_BlitSurface(font, &(SDL_Rect){245,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'q'){SDL_BlitSurface(font, &(SDL_Rect){251,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'r'){SDL_BlitSurface(font, &(SDL_Rect){257,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == 's'){SDL_BlitSurface(font, &(SDL_Rect){261,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == 't'){SDL_BlitSurface(font, &(SDL_Rect){266,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == 'u'){SDL_BlitSurface(font, &(SDL_Rect){270,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'v'){SDL_BlitSurface(font, &(SDL_Rect){276,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'w'){SDL_BlitSurface(font, &(SDL_Rect){282,0,8,9}, o, &dr); dr.x += 8+m;}
        else if(s[i] == 'x'){SDL_BlitSurface(font, &(SDL_Rect){290,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'y'){SDL_BlitSurface(font, &(SDL_Rect){296,0,6,11}, o, &dr); dr.x += 6+m;}
        else if(s[i] == 'z'){SDL_BlitSurface(font, &(SDL_Rect){302,0,5,9}, o, &dr); dr.x += 5+m;}
        else if(s[i] == '0'){SDL_BlitSurface(font, &(SDL_Rect){307,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '1'){SDL_BlitSurface(font, &(SDL_Rect){313,0,4,9}, o, &dr); dr.x += 4+m;}
        else if(s[i] == '2'){SDL_BlitSurface(font, &(SDL_Rect){317,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '3'){SDL_BlitSurface(font, &(SDL_Rect){323,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '4'){SDL_BlitSurface(font, &(SDL_Rect){329,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '5'){SDL_BlitSurface(font, &(SDL_Rect){335,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '6'){SDL_BlitSurface(font, &(SDL_Rect){341,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '7'){SDL_BlitSurface(font, &(SDL_Rect){347,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '8'){SDL_BlitSurface(font, &(SDL_Rect){353,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == '9'){SDL_BlitSurface(font, &(SDL_Rect){359,0,6,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == ':'){SDL_BlitSurface(font, &(SDL_Rect){365,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == '.'){SDL_BlitSurface(font, &(SDL_Rect){367,0,2,9}, o, &dr); dr.x += 2+m;}
        else if(s[i] == '+'){SDL_BlitSurface(font, &(SDL_Rect){369,0,7,9}, o, &dr); dr.x += 7+m;}
        else if(s[i] == '-'){dr.x++; SDL_BlitSurface(font, &(SDL_Rect){376,0,4,9}, o, &dr); dr.x += 6+m;}
        else if(s[i] == ' '){dr.x += 2+m;}
    }
    return dr.x;
}

int lenText(const char* s)
{
    int x = 0;
    static const int m = 1;
    const Uint32 len = strlen(s);
    for(Uint32 i = 0; i < len; i++)
    {
             if(s[i] == 'A'){x += 7+m;}
        else if(s[i] == 'B'){x += 6+m;}
        else if(s[i] == 'C'){x += 6+m;}
        else if(s[i] == 'D'){x += 7+m;}
        else if(s[i] == 'E'){x += 5+m;}
        else if(s[i] == 'F'){x += 5+m;}
        else if(s[i] == 'G'){x += 7+m;}
        else if(s[i] == 'H'){x += 7+m;}
        else if(s[i] == 'I'){x += 4+m;}
        else if(s[i] == 'J'){x += 5+m;}
        else if(s[i] == 'K'){x += 6+m;}
        else if(s[i] == 'L'){x += 5+m;}
        else if(s[i] == 'M'){x += 9+m;}
        else if(s[i] == 'N'){x += 6+m;}
        else if(s[i] == 'O'){x += 7+m;}
        else if(s[i] == 'P'){x += 6+m;}
        else if(s[i] == 'Q'){x += 7+m;}
        else if(s[i] == 'R'){x += 7+m;}
        else if(s[i] == 'S'){x += 6+m;}
        else if(s[i] == 'T'){x += 6+m;}
        else if(s[i] == 'U'){x += 7+m;}
        else if(s[i] == 'V'){x += 6+m;}
        else if(s[i] == 'W'){x += 10+m;}
        else if(s[i] == 'X'){x += 6+m;}
        else if(s[i] == 'Y'){x += 6+m;}
        else if(s[i] == 'Z'){x += 6+m;}
        else if(s[i] == 'a'){x += 6+m;}
        else if(s[i] == 'b'){x += 6+m;}
        else if(s[i] == 'c'){x += 5+m;}
        else if(s[i] == 'd'){x += 6+m;}
        else if(s[i] == 'e'){x += 6+m;}
        else if(s[i] == 'f'){x += 3+m;}
        else if(s[i] == 'g'){x += 6+m;}
        else if(s[i] == 'h'){x += 6+m;}
        else if(s[i] == 'i'){x += 2+m;}
        else if(s[i] == 'j'){x += 3+m;}
        else if(s[i] == 'k'){x += 6+m;}
        else if(s[i] == 'l'){x += 2+m;}
        else if(s[i] == 'm'){x += 10+m;}
        else if(s[i] == 'n'){x += 6+m;}
        else if(s[i] == 'o'){x += 6+m;}
        else if(s[i] == 'p'){x += 6+m;}
        else if(s[i] == 'q'){x += 6+m;}
        else if(s[i] == 'r'){x += 4+m;}
        else if(s[i] == 's'){x += 5+m;}
        else if(s[i] == 't'){x += 4+m;}
        else if(s[i] == 'u'){x += 6+m;}
        else if(s[i] == 'v'){x += 6+m;}
        else if(s[i] == 'w'){x += 8+m;}
        else if(s[i] == 'x'){x += 6+m;}
        else if(s[i] == 'y'){x += 6+m;}
        else if(s[i] == 'z'){x += 5+m;}
        else if(s[i] == '0'){x += 6+m;}
        else if(s[i] == '1'){x += 4+m;}
        else if(s[i] == '2'){x += 6+m;}
        else if(s[i] == '3'){x += 6+m;}
        else if(s[i] == '4'){x += 6+m;}
        else if(s[i] == '5'){x += 6+m;}
        else if(s[i] == '6'){x += 6+m;}
        else if(s[i] == '7'){x += 6+m;}
        else if(s[i] == '8'){x += 6+m;}
        else if(s[i] == '9'){x += 6+m;}
        else if(s[i] == ':'){x += 2+m;}
        else if(s[i] == '.'){x += 2+m;}
        else if(s[i] == '+'){x += 7+m;}
        else if(s[i] == '-'){x += 7+m;}
        else if(s[i] == ' '){x += 2+m;}
    }
    return x;
}

//*************************************
// update & render
//*************************************
void WOX_QUIT()
{
    SDL_HideWindow(wnd);
    saveState("");
    drawText(NULL, "*K", 0, 0, 0);
    SDL_FreeSurface(s_icon);
    SDL_FreeSurface(sHud);
    SDL_GL_DeleteContext(glc);
    SDL_DestroyWindow(wnd);
    SDL_Quit();
    exit(0);
}
void WOX_POP(const int w, const int h)
{
    winw = w;
    winh = h;
    winw2 = winw/2;
    winh2 = winh/2;
    doPerspective();
}
void main_loop()
{
//*************************************
// time delta for interpolation
//*************************************
    static float lt = 0;
    t = fTime();
    const float dt = t-lt;
    lt = t;

//*************************************
// input handling
//*************************************
    
    // if user is idle for 3 minutes, save.
    static float idle = 0.f;
    if(idle != 0.f && t-idle > 180.f)
    {
        // char tmp[32];
        // tmp[0] = '.';
        // tmp[1] = 'i';
        // tmp[2] = 'd';
        // tmp[3] = 'l';
        // tmp[4] = 'e';
        // tmp[5] = '.';
        // const time_t tt = time(0);
        // strftime(&tmp[6], 32, "%d-%m-%y_%H:%M:%S", localtime(&tt));
        saveState(".idle");
        idle = 0.f; // so we only save once
        // on input a new idle is set, and a
        // count-down for a new save begins.
    }

    // window decor stuff
    // if(drag == 1)
    // {
    //     static int lx=0, ly=0;
    //     static float lt = 0;
    //     if(t > lt)
    //     {
    //         if(lx != mx || ly != my)
    //         {
    //             int x,y;
    //             SDL_GetWindowPosition(wnd, &x, &y);
    //             SDL_SetWindowPosition(wnd, x+(mx-dsx), y+(my-dsy));
    //             lx = mx, ly = my;
    //         }
    //         lt = t+0.03f;
    //     }
    // }
    if(size == 1)
    {
        static float lt = 0;
        if(t > lt)
        {
            int w,h;
            SDL_GetWindowSize(wnd, &w, &h);
            winw = w+(mx-dsx);
            winh = h+(my-dsy);
            dsx = mx;
            dsy = my;
            if(winw > 520 && winh > 380)
            {
                SDL_SetWindowSize(wnd, winw, winh);
                winw2 = winw/2;
                winh2 = winh/2;
                doPerspective();
            }
            lt = t+0.03f;
        }
    }
    
    static uint last_focus_mouse = 0;
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_WINDOWEVENT:
            {
                switch(event.window.event)
                {
                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                    {
                        focus_mouse = last_focus_mouse;
                        SDL_ShowCursor(focus_mouse ? SDL_DISABLE : SDL_ENABLE);
                        if(focus_mouse == 1)
                        {
                            SDL_GetRelativeMouseState(&xd, &yd);
                            SDL_SetRelativeMouseMode(SDL_TRUE);
                        }
                    }
                    break;

                    case SDL_WINDOWEVENT_FOCUS_LOST:
                    {
                        last_focus_mouse = focus_mouse;
                        focus_mouse = 0;
                        SDL_ShowCursor(SDL_ENABLE);
                        SDL_GetRelativeMouseState(&xd, &yd);
                        SDL_SetRelativeMouseMode(SDL_FALSE);
                    }
                    break;

                    case SDL_WINDOWEVENT_RESIZED:
                    {
                        WOX_POP(event.window.data1, event.window.data2);
                    }
                    break;
                }
            }
            break;

            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_TAB) // unlock mouse focus
                {
                    focus_mouse = 1 - focus_mouse;
                    SDL_ShowCursor(1 - focus_mouse);
                    if(focus_mouse == 1)
                    {
                        SDL_GetRelativeMouseState(&xd, &yd);
                        SDL_SetRelativeMouseMode(SDL_TRUE);
                    }
                    else
                    {
                        SDL_GetRelativeMouseState(&xd, &yd);
                        SDL_SetRelativeMouseMode(SDL_FALSE);
                    }
                }
                if(focus_mouse == 0){break;}
                if(event.key.keysym.sym == SDLK_w){ks[0] = 1;}
                else if(event.key.keysym.sym == SDLK_a){ks[1] = 1;}
                else if(event.key.keysym.sym == SDLK_s){ks[2] = 1;}
                else if(event.key.keysym.sym == SDLK_d){ks[3] = 1;}
                else if(event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_LCTRL){ks[4] = 1;} // move down Z
                else if(event.key.keysym.sym == SDLK_LEFT){ks[5] = 1;}
                else if(event.key.keysym.sym == SDLK_RIGHT){ks[6] = 1;}
                else if(event.key.keysym.sym == SDLK_UP){ks[7] = 1;}
                else if(event.key.keysym.sym == SDLK_DOWN){ks[8] = 1;}
                else if(event.key.keysym.sym == SDLK_SPACE){ks[9] = 1;} // move up Z
                else if(event.key.keysym.sym == SDLK_q) // clone pointed voxel texture
                {
                    if(ise == 0)
                    {
                        traceViewPath(0);
                        if(lray > -1){sp1 = g.voxels[lray];}else{sdif=(vec){0.f,0.f,0.f};}
                        //printf("DOWN: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                        ise = 1;
                    }
                }
                else if(event.key.keysym.sym == SDLK_SLASH || event.key.keysym.sym == SDLK_x) // - change selected node
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        g.st = g.voxels[lray].w - 1.f;
                        if(g.st < 0.f){g.st = 16.f;}
                        g.voxels[lray].w = g.st;

                        if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                        {
                            for(uint i = 0; i < g.num_voxels; i++)
                            {
                                if(g.voxels[i].w < 0.f){continue;}
                                float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                                if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                                if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                                if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                                if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                    g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                    g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                                {
                                    g.voxels[i].w = g.st;
                                }
                            }
                        }
                    }
                    else
                    {
                        g.st -= 1.f;
                        if(g.st < 0.f){g.st = 16.f;}
                    }
                }
                else if(event.key.keysym.sym == SDLK_QUOTE || event.key.keysym.sym == SDLK_c) // + change selected node
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        g.st = g.voxels[lray].w + 1.f;
                        if(g.st > 16.f){g.st = 0.f;}
                        g.voxels[lray].w = g.st;

                        if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                        {
                            for(uint i = 0; i < g.num_voxels; i++)
                            {
                                if(g.voxels[i].w < 0.f){continue;}
                                float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                                if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                                if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                                if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                                if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                    g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                    g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                                {
                                    g.voxels[i].w = g.st;
                                }
                            }
                        }
                    }
                    else
                    {
                        g.st += 1.f;
                        if(g.st > 16.f){g.st = 0.f;}
                    }
                }
                else if(event.key.keysym.sym == SDLK_RCTRL) // remove pointed voxel
                {
                    dtt = t+0.3f;
                    traceViewPath(0);
                    if(lray > 0){g.voxels[lray].w = -1.f;}
                }
                else if(event.key.keysym.sym == SDLK_RSHIFT) // place a voxel
                {
                    traceViewPath(1);
                    placeVoxel(0.3f);
                }
                else if(event.key.keysym.sym == SDLK_g) // gravity toggle
                {
                    g.grav = 1 - g.grav;
                }
                else if(event.key.keysym.sym == SDLK_e || event.key.keysym.sym == SDLK_f) // change movement speeds
                {
                    fks = 1 - fks;
                    if(fks){g.ms = g.cms;}
                       else{g.ms = g.lms;}
                }
                else if(event.key.keysym.sym == SDLK_1) // change movement speeds
                {
                    g.ms = 9.3f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_2) // change movement speeds
                {
                    g.ms = 18.6f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_3) // change movement speeds
                {
                    g.ms = 37.2f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_4) // change movement speeds
                {
                    g.ms = 74.4f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_5) // change movement speeds
                {
                    g.ms = 148.8f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_6) // change movement speeds
                {
                    g.ms = 297.6f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_7) // change movement speeds
                {
                    g.ms = 595.2f;
                    if(fks){g.cms=g.ms;}else{g.lms=g.ms;}
                }
                else if(event.key.keysym.sym == SDLK_t)
                {
                    defaultState(1);
                }
                else if(event.key.keysym.sym == SDLK_r)
                {
                    vec p = g.pp;
                    vInv(&p);
                    vec pi = look_dir;
                    vMulS(&pi, pi, 6.f);
                    vAdd(&p, p, pi);
                    placeVoxelArb((vec){roundf(p.x), roundf(p.y), roundf(p.z), g.st});
                }
                else if(event.key.keysym.sym == SDLK_v)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;} // no selection
                    
                    // check pointed node is not within selection
                    uint good = 1;
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                        if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                        if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                        if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                        if( g.voxels[lray].x >= lx && g.voxels[lray].x <= hx &&
                            g.voxels[lray].y >= ly && g.voxels[lray].y <= hy &&
                            g.voxels[lray].z >= lz && g.voxels[lray].z <= hz )
                        {
                            good = 0;
                        }
                    }else{good=0;}
                    if(good == 1)
                    {
                        // copy nodes to new position, from sp1o to g.voxels[lray]
                        for(uint i = 0; i < g.num_voxels; i++)
                        {
                            if(g.voxels[i].w < 0.f){continue;}
                            float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                            if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                            if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                            if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                            if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                            {
                                forceVoxelArb((vec){g.voxels[lray].x+(g.voxels[i].x-sp1o.x),
                                                    g.voxels[lray].y+(g.voxels[i].y-sp1o.y),
                                                    g.voxels[lray].z+(g.voxels[i].z-sp1o.z),
                                                    g.voxels[i].w});
                            }
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_b)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;}

                    const float xinc = sdifo.x > 0.f ? 1.f : -1.f;
                    for(float x = sp1o.x; x != sp2.x+xinc; x += xinc)
                    {
                        const float yinc = sdifo.y > 0.f ? 1.f : -1.f;
                        for(float y = sp1o.y; y != sp2.y+yinc; y += yinc)
                        {
                            const float zinc = sdifo.z > 0.f ? 1.f : -1.f;
                            for(float z = sp1o.z; z != sp2.z+zinc; z += zinc)
                            {
                                uint df = 0;
                                for(uint i = 0; i < g.num_voxels; i++)
                                {
                                    if(g.voxels[i].x == x && g.voxels[i].y == y && g.voxels[i].z == z)
                                    {
                                        g.voxels[i].w = g.st;
                                        df=1;
                                    }
                                }
                                if(df == 0)
                                {
                                    uint df2 = 0;
                                    for(uint i = 0; i < g.num_voxels; i++)
                                    {
                                        if(g.voxels[i].w < 0.f)
                                        {
                                            g.voxels[i] = (vec){x,y,z,g.st};
                                            df2 = 1;
                                            break;
                                        }
                                    }
                                    if(df2 == 0 && g.num_voxels < max_voxels)
                                    {
                                        g.voxels[g.num_voxels] = (vec){x,y,z,g.st};
                                        const int r = g.num_voxels;
                                        g.num_voxels++;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_n)
                {
                    if(sdif.x == 0.f && sdif.y == 0.f && sdif.z == 0.f){break;}
                    for(uint i = 0; i < g.num_voxels; i++)
                    {
                        if(g.voxels[i].w < 0.f){continue;}
                        float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                        if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                        if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                        if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                        if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                            g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                            g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                        {
                            g.voxels[i].w = -1.f;
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_F3)
                {
                    saveState("");
                }
                else if(event.key.keysym.sym == SDLK_F8)
                {
                    loadState();
                }
#ifdef __linux__
                else if(event.key.keysym.sym == SDLK_F10) // export
                {
                    char tmp[32];
                    const time_t tt = time(0);
                    strftime(tmp, 32, "%d-%m-%y_%H:%M:%S", localtime(&tt));
                    char cmd[512];
                    sprintf(cmd, "%s/EXPORTS", getenv("HOME"));
                    mkdir(cmd, 0755);
                    sprintf(cmd, "%s/EXPORTS/VoxelPaint_exports", getenv("HOME"));
                    mkdir(cmd, 0755);
                    char tmp2[16];
                    timestamp(tmp2);
                    if(fileExist("/usr/bin/7z") == 1)
                    {
                        sprintf(cmd, "/usr/bin/7z a -y -bsp0 -bso0 -r %s/EXPORTS/VoxelPaint_exports/voxelpaint_%s_%u.7z %s/*", getenv("HOME"), tmp, g.num_voxels, appdir);
                        if(system(cmd) < 0){printf("system() failed: %s\n", cmd);}
                        printf("[%s] Exported data to: %s/EXPORTS/VoxelPaint_exports/voxelpaint_%s_%u.7z\n", tmp2, getenv("HOME"), tmp, g.num_voxels);
                    }
                    else if(fileExist("/usr/bin/zip") == 1)
                    {
                        sprintf(cmd, "/usr/bin/zip -jq9 %s/EXPORTS/VoxelPaint_exports/voxelpaint_%s_%u.zip %s/world.db %s/world.db2 %s/world.gz %s/tiles.ppm", getenv("HOME"), tmp, g.num_voxels, appdir, appdir, appdir, appdir);
                        if(system(cmd) < 0){printf("system() failed: %s\n", cmd);}
                        printf("[%s] Exported data to: %s/EXPORTS/VoxelPaint_exports/voxelpaint_%s_%u.zip\n", tmp2, getenv("HOME"), tmp, g.num_voxels);
                    }
                    else
                    {
                        printf("[%s] Unable to export. `/usr/bin/7z` or `/usr/bin/zip` could not be located.\n", tmp2);
                    }
                    
                }
#endif
#ifdef VERBOSE
                else if(event.key.keysym.sym == SDLK_p)
                {
                    for(int i = 0; i < 100000; i++)
                    {   // none of these voxels are grid-aligned without the roundf()
                        if(g.num_voxels >= max_voxels){break;}
                        g.voxels[g.num_voxels] = (vec){roundf(randfc()*ddist), roundf(randfc()*ddist), roundf(randfc()*ddist), esRand(0, 16)};
                        g.num_voxels++;
                    }
                }
#else
                else if(event.key.keysym.sym == SDLK_p)
                {
                    g.plock = 1 - g.plock;
                }
#endif
                idle = t;
            }
            break;

            case SDL_KEYUP:
            {
                if(focus_mouse == 0){break;}
                if(event.key.keysym.sym == SDLK_w){ks[0] = 0;}
                else if(event.key.keysym.sym == SDLK_a){ks[1] = 0;}
                else if(event.key.keysym.sym == SDLK_s){ks[2] = 0;}
                else if(event.key.keysym.sym == SDLK_d){ks[3] = 0;}
                else if(event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_LCTRL){ks[4] = 0;}
                else if(event.key.keysym.sym == SDLK_LEFT){ks[5] = 0;}
                else if(event.key.keysym.sym == SDLK_RIGHT){ks[6] = 0;}
                else if(event.key.keysym.sym == SDLK_UP){ks[7] = 0;}
                else if(event.key.keysym.sym == SDLK_DOWN){ks[8] = 0;}
                else if(event.key.keysym.sym == SDLK_SPACE){ks[9] = 0;}
                else if(event.key.keysym.sym == SDLK_RSHIFT){ptt = 0.f;}
                else if(event.key.keysym.sym == SDLK_RCTRL){dtt = 0.f;}
                else if(event.key.keysym.sym == SDLK_q) // clone pointed voxel texture
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        g.st = g.voxels[lray].w;
                        sp2 = g.voxels[lray];
                        if(sp1.x == sp2.x && sp1.y == sp2.y && sp1.z == sp2.z)
                        {
                            sdif=(vec){0.f,0.f,0.f};
                            ise = 0;
                        }
                        else
                        {
                            sp1o = sp1;
                            sp1d = sp1;
                            sdif = sp2;
                            vSub(&sdif, sdif, sp1);
                            sdifo = sdif;
                            if(sdif.x < 0.f){sp1d.x += 0.51f;sdif.x -= 1.02f;}else{sp1d.x -= 0.51f;sdif.x += 1.02f;}
                            if(sdif.y < 0.f){sp1d.y += 0.51f;sdif.y -= 1.02f;}else{sp1d.y -= 0.51f;sdif.y += 1.02f;}
                            if(sdif.z < 0.f){sp1d.z += 0.51f;sdif.z -= 1.02f;}else{sp1d.z -= 0.51f;sdif.z += 1.02f;}
                        }
                        //printf("UP: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                    }
                    ise = 0;
                }
                idle = t;
            }
            break;

            case SDL_MOUSEWHEEL: // change selected node
            {
                if(focus_mouse == 0){break;}

                bigc = t+0.5f;

                if(event.wheel.y > 0)
                {
                    g.st += 1.f;
                    if(g.st > 16.f){g.st = 0.f;}
                }
                else if(event.wheel.y < 0)
                {
                    g.st -= 1.f;
                    if(g.st < 0.f){g.st = 16.f;}
                }

                if(ise == 0)
                {
                    if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
                    {
                        for(uint i = 0; i < g.num_voxels; i++)
                        {
                            if(g.voxels[i].w < 0.f){continue;}
                            float lx=0.f,ly=0.f,lz=0.f,hx=0.f,hy=0.f,hz=0.f;
                            if(sp1o.x < sp2.x){lx=sp1o.x;hx=sp2.x;}else{lx=sp2.x;hx=sp1o.x;}
                            if(sp1o.y < sp2.y){ly=sp1o.y;hy=sp2.y;}else{ly=sp2.y;hy=sp1o.y;}
                            if(sp1o.z < sp2.z){lz=sp1o.z;hz=sp2.z;}else{lz=sp2.z;hz=sp1o.z;}
                            if( g.voxels[i].x >= lx && g.voxels[i].x <= hx &&
                                g.voxels[i].y >= ly && g.voxels[i].y <= hy &&
                                g.voxels[i].z >= lz && g.voxels[i].z <= hz )
                            {
                                g.voxels[i].w = g.st;
                            }
                        }
                    }
                }
            }
            break;

            case SDL_MOUSEMOTION:
            {
                mx = event.motion.x;
                my = event.motion.y;
                if(focus_mouse == 0){break;}

                if(ise == 1)
                {
                    static float nt = 0.f;
                    if(t > nt)
                    {
                        traceViewPath(0);
                        if(lray > -1)
                        {
                            g.st = g.voxels[lray].w;
                            sp2 = g.voxels[lray];

                            if(sp1.x != sp2.x || sp1.y != sp2.y || sp1.z != sp2.z)
                            {
                                sp1o = sp1;
                                sp1d = sp1;
                                sdif = sp2;
                                vSub(&sdif, sdif, sp1);
                                sdifo = sdif;
                                if(sdif.x < 0.f){sp1d.x += 0.51f;sdif.x -= 1.02f;}else{sp1d.x -= 0.51f;sdif.x += 1.02f;}
                                if(sdif.y < 0.f){sp1d.y += 0.51f;sdif.y -= 1.02f;}else{sp1d.y -= 0.51f;sdif.y += 1.02f;}
                                if(sdif.z < 0.f){sp1d.z += 0.51f;sdif.z -= 1.02f;}else{sp1d.z -= 0.51f;sdif.z += 1.02f;}
                            }
                        }
                        nt = t+0.06f;
                    }
                }

                idle = t;
            }
            break;

            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    if(size == 1)
                    {
                        size=0;
                        SDL_GetWindowSize(wnd, &winw, &winh);
                        WOX_POP(winw, winh);
                        SDL_CaptureMouse(SDL_FALSE);
                    }
                    ptt = 0.f;
                }
                else if(event.button.button == SDL_BUTTON_RIGHT){dtt = 0.f;}
                else if(event.button.button == SDL_BUTTON_MIDDLE) // clone pointed voxel
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        g.st = g.voxels[lray].w;
                        sp2 = g.voxels[lray];
                        if(sp1.x == sp2.x && sp1.y == sp2.y && sp1.z == sp2.z)
                        {
                            sdif=(vec){0.f,0.f,0.f};
                            ise = 0;
                            //bigc = t+0.25f;
                        }
                        else
                        {
                            sp1o = sp1;
                            sp1d = sp1;
                            sdif = sp2;
                            vSub(&sdif, sdif, sp1);
                            sdifo = sdif;
                            if(sdif.x < 0.f){sp1d.x += 0.51f;sdif.x -= 1.02f;}else{sp1d.x -= 0.51f;sdif.x += 1.02f;}
                            if(sdif.y < 0.f){sp1d.y += 0.51f;sdif.y -= 1.02f;}else{sp1d.y -= 0.51f;sdif.y += 1.02f;}
                            if(sdif.z < 0.f){sp1d.z += 0.51f;sdif.z -= 1.02f;}else{sp1d.z -= 0.51f;sdif.z += 1.02f;}
                        }
                        //printf("UP: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                    }
                    ise = 0;
                }
                md = 0;
                idle = t;
            }
            break;

            case SDL_MOUSEBUTTONDOWN:
            {
                mx = event.button.x;
                my = event.button.y;

                static float llct = 0.f;

                if(event.button.button == SDL_BUTTON_LEFT) // check window decor stuff
                {
                    if(focus_mouse == 0)
                    {
                        if(llct != 0.f && t-llct < 0.3f)
                        {
                            maxed = 1 - maxed;
                            if(maxed == 1)
                            {
                                SDL_MaximizeWindow(wnd);
                                size = 0;
                                llct = t;
                                break;
                            }
                            else
                            {
                                SDL_RestoreWindow(wnd);
                                size = 0;
                                llct = t;
                                break;
                            }
                        }
                        llct = t;
                        if(my < 22)
                        {
                            if(mx < 14)
                            {
                                WOX_QUIT();
                                break;
                            }
                            else if(mx < 24)
                            {
                                SDL_MinimizeWindow(wnd);
                                break;
                            }
                            else if(mx < 40)
                            {
                                maxed = 1 - maxed;
                                if(maxed == 1){SDL_MaximizeWindow(wnd);}
                                else{SDL_RestoreWindow(wnd);}
                                break;
                            }
                            else if(mx > winw-14)
                            {
                                WOX_QUIT();
                                break;
                            }
                            else if(mx > winw-24)
                            {
                                SDL_MinimizeWindow(wnd);
                                break;
                            }
                            else if(mx > winw-40)
                            {
                                maxed = 1 - maxed;
                                if(maxed == 1){SDL_MaximizeWindow(wnd);}
                                else{SDL_RestoreWindow(wnd);}
                                break;
                            }

                            dsx = mx, dsy = my;
                            break;
                        }
                        else if(mx > winw-15 && my > winh-15)
                        {
                            size = 1;
                            dsx = mx, dsy = my;
                            SDL_CaptureMouse(SDL_TRUE);
                            break;
                        }
                    }
                }

                if(focus_mouse == 0) // lock mouse focus on every mouse input to the window
                {
                    SDL_ShowCursor(0);
                    focus_mouse = 1;
                    SDL_GetRelativeMouseState(&xd, &yd);
                    SDL_SetRelativeMouseMode(SDL_TRUE);
                    break;
                }

                if(event.button.button == SDL_BUTTON_LEFT) // place a voxel
                {
                    traceViewPath(1);
                    placeVoxel(0.3f);
                }
                else if(event.button.button == SDL_BUTTON_RIGHT) // remove pointed voxel
                {
                    dtt = t+0.3f;
                    traceViewPath(0);
                    if(lray > 0){g.voxels[lray].w = -1.f;}
                }
                else if(event.button.button == SDL_BUTTON_MIDDLE) // clone pointed voxel
                {
                    traceViewPath(0);
                    if(lray > -1){sp1 = g.voxels[lray];}else{sdif=(vec){0.f,0.f,0.f};}
                    //printf("DOWN: %.2f, %.2f, %.2f\n", g.voxels[lray].x, g.voxels[lray].y, g.voxels[lray].z);
                    ise = 1;
                }
                else if(event.button.button == SDL_BUTTON_X1) // change movement speeds
                {
                    fks = 1 - fks;
                    if(fks){g.ms = g.cms;}
                       else{g.ms = g.lms;}
                }
                idle = t;
            }
            break;

            case SDL_QUIT:
            {
                WOX_QUIT();
            }
            break;
        }
    }

//*************************************
// keystates
//*************************************
    if(focus_mouse == 1)
    {
        mGetViewZ(&look_dir, view);

        if(g.grav == 1 || g.plock == 1)
        {
            look_dir.z = -0.001f;
            vNorm(&look_dir);
        }

        if(ptt != 0.f && t > ptt) // place trigger
        {
            traceViewPath(1);
            placeVoxel(0.1f);
        }
        
        if(dtt != 0.f && t > dtt) // delete trigger
        {
            traceViewPath(0);
            if(lray > 0){g.voxels[lray].w = -1.f;}
            dtt = t+0.1f;
        }

        if(ks[0] == 1) // W
        {
            vec m;
            vMulS(&m, look_dir, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[2] == 1) // S
        {
            vec m;
            vMulS(&m, look_dir, g.ms * dt);
            vAdd(&g.pp, g.pp, m);
        }

        if(ks[1] == 1) // A
        {
            vec vdc;
            mGetViewX(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[3] == 1) // D
        {
            vec vdc;
            mGetViewX(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vAdd(&g.pp, g.pp, m);
        }

        if(ks[4] == 1) // LSHIFT (down)
        {
            vec vdc;
            if(g.plock == 1)
                vdc = (vec){0.f,0.f,-1.f};
            else
                mGetViewY(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[9] == 1) // SPACE (up)
        {
            vec vdc;
            if(g.plock == 1)
                vdc = (vec){0.f,0.f,-1.f};
            else
                mGetViewY(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vAdd(&g.pp, g.pp, m);
        }

        if(ks[5] == 1) // LEFT
            g.xrot += 1.f*dt;
        else if(ks[6] == 1) // RIGHT
            g.xrot -= 1.f*dt;

        if(ks[7] == 1) // UP
            g.yrot += 1.f*dt;
        else if(ks[8] == 1) // DOWN
            g.yrot -= 1.f*dt;

        // player gravity
        if(g.grav == 1)
        {
            static uint falling = 0;

            vec vipp = g.pp; // inverse player position (setting global 'ipp' here is perfect)
            vInv(&vipp); // <--
            vipp.x = roundf(vipp.x);
            vipp.y = roundf(vipp.y);
            vipp.z = roundf(vipp.z); // now vipp is voxel aligned

            falling = 1;
            for(int j = 0; j < g.num_voxels; j++)
            {
                if(g.voxels[j].x == vipp.x && g.voxels[j].y == vipp.y && g.voxels[j].z == vipp.z-1.f)
                {
                    falling = 0;
                    break;
                }

                if(g.voxels[j].x == vipp.x && g.voxels[j].y == vipp.y && g.voxels[j].z == vipp.z-2.f)
                {
                    falling = 2;
                    break;
                }
            }
            // this extra loop makes you auto climb ALL nodes 
            for(int j = 0; j < g.num_voxels; j++)
            {
                if(g.voxels[j].x == vipp.x && g.voxels[j].y == vipp.y && g.voxels[j].z == vipp.z-1.f)
                {
                    falling = 0;
                    break;
                }
            }
            if(falling == 1)        {g.pp.z += (g.ms*0.5f)*dt;}
            else if(falling == 0)   {g.pp.z -= g.ms*dt;}

            mGetViewZ(&look_dir, view);
        }

    //*************************************
    // camera/mouse control
    //*************************************
        SDL_GetRelativeMouseState(&xd, &yd);
        if(xd != 0 || yd != 0)
        {
            g.xrot -= xd*g.sens;
            g.yrot -= yd*g.sens;

            if(g.plock == 1)
            {
                if(g.yrot > 3.11f)
                    g.yrot = 3.11f;
                if(g.yrot < 0.03f)
                    g.yrot = 0.03f;
            }
            else
            {
                if(g.yrot > 3.14f)
                    g.yrot = 3.14f;
                if(g.yrot < 0.1f)
                    g.yrot = 0.1f;
            }
        }
    }

    mIdent(&view);
    mRotate(&view, g.yrot, 1.f, 0.f, 0.f);
    mRotate(&view, g.xrot, 0.f, 0.f, 1.f);
    mTranslate(&view, g.pp.x, g.pp.y, g.pp.z);

    mGetViewZ(&look_dir, view); // refresh

//*************************************
// begin render
//*************************************
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//*************************************
// main render
//*************************************

    // voxels
    static uint sswi = 0;
    if(sswi == 0)
    {
        shadeVoxel(&position_id, &projection_id, &view_id, &voxel_id, &normal_id, &texcoord_id, &sampler_id);
        glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);

        glBindBuffer(GL_ARRAY_BUFFER, mdlVoxel.vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, mdlVoxel.nid);
        glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(normal_id);

        glBindBuffer(GL_ARRAY_BUFFER, mdlVoxel.tid);
        glVertexAttribPointer(texcoord_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(texcoord_id);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texmap);
        glUniform1i(sampler_id, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlVoxel.iid);
        sswi = 1;
    }

    // render voxels
    ipp = g.pp; // inverse player position (setting global 'ipp' here is perfect)
    vInv(&ipp); // <--
    glUniformMatrix4fv(view_id, 1, GL_FALSE, (float*)&view.m[0][0]);
    mGetViewZ(&look_dir, view);
    for(int j = 0; j < g.num_voxels; j++)
    {
        if(g.voxels[j].w < 0.f || 
            vDistSq(ipp, g.voxels[j]) >= ddist2 ||
            insideFrustum(g.voxels[j].x, g.voxels[j].y, g.voxels[j].z) == 0){continue;}

        glUniform4f(voxel_id, g.voxels[j].x, g.voxels[j].y, g.voxels[j].z, g.voxels[j].w);
        glDrawElements(GL_TRIANGLES, voxel_numind, GL_UNSIGNED_BYTE, 0);
    }

    // render selection area
    if(sdif.x != 0.f && sdif.y != 0.f && sdif.z != 0.f)
    {
        glUniform4f(voxel_id, 0.f,0.f,0.f, 10.f);
        esRebind(GL_ARRAY_BUFFER, &mdlVoxel.vid, &(GLfloat[]){
                                                                sp1d.x, sp1d.y, sp1d.z,
                                                                sp1d.x+sdif.x, sp1d.y, sp1d.z,
                                                                sp1d.x+sdif.x, sp1d.y+sdif.y, sp1d.z,
                                                                sp1d.x, sp1d.y+sdif.y, sp1d.z,
                                                                //
                                                                sp1d.x, sp1d.y, sp1d.z+sdif.z,
                                                                sp1d.x+sdif.x, sp1d.y, sp1d.z+sdif.z,
                                                                sp1d.x+sdif.x, sp1d.y+sdif.y, sp1d.z+sdif.z,
                                                                sp1d.x, sp1d.y+sdif.y, sp1d.z+sdif.z,
                                                                sp1d.x, sp1d.y, sp1d.z+sdif.z,
                                                            }
                                                            , 10 * 3 * sizeof(float), GL_STATIC_DRAW);
        const vec v = (vec){-look_dir.x, -look_dir.y, -look_dir.z};
        esRebind(GL_ARRAY_BUFFER,         &mdlVoxel.nid, &(vec[]){v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z, v.x,v.y,v.z}, 10 * 3 * sizeof(float),  GL_STATIC_DRAW);
        esRebind(GL_ELEMENT_ARRAY_BUFFER, &mdlVoxel.iid, &(GLbyte[]){0,1,2,3,0,4,5,6,7,8,5,1,2,6,7,3}, 16,  GL_STATIC_DRAW); // could probably be reduced more
        glDrawElements(GL_LINE_STRIP, voxel_numind, GL_UNSIGNED_BYTE, 0);
        esRebind(GL_ARRAY_BUFFER,         &mdlVoxel.vid, voxel_vertices, sizeof(voxel_vertices), GL_STATIC_DRAW);
        esRebind(GL_ARRAY_BUFFER,         &mdlVoxel.nid, voxel_normals,  sizeof(voxel_normals),  GL_STATIC_DRAW);
        esRebind(GL_ELEMENT_ARRAY_BUFFER, &mdlVoxel.iid, voxel_indices,  sizeof(voxel_indices),  GL_STATIC_DRAW);
    }

    // crosshair
    mGetViewZ(&look_dir, view);
    float cdi = 130.f;
    if(t < bigc){cdi = 50.f;}
    const float nx = ipp.x+(look_dir.x*cdi), ny = ipp.y+(look_dir.y*cdi), nz = ipp.z+(look_dir.z*cdi);
    glUniform4f(voxel_id, nx, ny, nz, g.st);
    glDisable(GL_DEPTH_TEST);
        glDrawElements(GL_TRIANGLES, voxel_numind, GL_UNSIGNED_BYTE, 0);
    glEnable(GL_DEPTH_TEST);

    // hud
    if(focus_mouse == 0)
    {
        shadeHud(&position_id, &texcoord_id, &sampler_id);
        glUniformMatrix4fv(projection_id, 1, GL_FALSE, (float*)&projection.m[0][0]);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, hudmap);
        glUniform1i(sampler_id, 0);
        glBindBuffer(GL_ARRAY_BUFFER, mdlPlane.vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);
        glBindBuffer(GL_ARRAY_BUFFER, mdlPlane.tid);
        glVertexAttribPointer(texcoord_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(texcoord_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mdlPlane.iid);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
            glDrawElements(GL_TRIANGLES, hud_numind, GL_UNSIGNED_BYTE, 0);
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        sswi = 0;
    }

//*************************************
// swap buffers / display render
//*************************************
    SDL_GL_SwapWindow(wnd);
}
void drawHud()
{
    // updated maxed state
    const uint flags = SDL_GetWindowFlags(wnd);
    if(flags & SDL_WINDOW_MAXIMIZED){maxed = 1;}else{maxed = 0;}

    // clear cpu hud before rendering to it
    SDL_FillRect(sHud, &sHud->clip_rect, 0x00000000);

    // window title
    SDL_FillRect(sHud, &(SDL_Rect){0, 0, winw, 19}, 0xDDd0e040);
    SDL_FillRect(sHud, &(SDL_Rect){1, 1, winw-2, 17}, 0xBBa0b010);
    const uint len = lenText("Voxel Paint");
    drawText(sHud, "Voxel Paint", winw2-24, 3, 2);
    drawText(sHud, "Voxel Paint", winw2-26, 3, 2);
    drawText(sHud, "Voxel Paint", winw2-25, 5, 2);
    drawText(sHud, "Voxel Paint", winw2-25, 4, 0);
    drawText(sHud, "X -", 5, 4, 3);
    drawText(sHud, "X -", 4, 5, 0);
    if(maxed == 0)
    {
        SDL_FillRect(sHud, &(SDL_Rect){25, 3, 11, 11}, 0xFF00BFFF);
        SDL_FillRect(sHud, &(SDL_Rect){24, 4, 11, 11}, 0xFF000000);
        SDL_FillRect(sHud, &(SDL_Rect){25, 5, 9, 9}, 0xBBa0b010);
    }
    else
    {
        SDL_FillRect(sHud, &(SDL_Rect){24, 4, 11, 11}, 0xFF00BFFF);
        SDL_FillRect(sHud, &(SDL_Rect){23, 3, 11, 11}, 0xFF000000);
        SDL_FillRect(sHud, &(SDL_Rect){24, 4, 9, 9}, 0xBBa0b010);
    }
    drawText(sHud, "- X", winw-23, 4, 3);
    drawText(sHud, "- X", winw-22, 5, 0);
    if(maxed == 0)
    {
        SDL_FillRect(sHud, &(SDL_Rect){winw-38, 3, 11, 11}, 0xFF00BFFF);
        SDL_FillRect(sHud, &(SDL_Rect){winw-37, 4, 11, 11}, 0xFF000000);
        SDL_FillRect(sHud, &(SDL_Rect){winw-36, 5, 9, 9}, 0xBBa0b010);
    }
    else
    {
        SDL_FillRect(sHud, &(SDL_Rect){winw-37, 4, 11, 11}, 0xFF00BFFF);
        SDL_FillRect(sHud, &(SDL_Rect){winw-36, 3, 11, 11}, 0xFF000000);
        SDL_FillRect(sHud, &(SDL_Rect){winw-35, 4, 9, 9}, 0xBBa0b010);
    }
    SDL_FillRect(sHud, &(SDL_Rect){winw-15, winh-15, 15, 15}, 0xDDd0e040);
    SDL_FillRect(sHud, &(SDL_Rect){winw-14, winh-14, 13, 13}, 0xBBa0b010);
    drawText(sHud, "r", winw-8, winh-12, 3);
    drawText(sHud, "r", winw-9, winh-13, 0);

    SDL_FillRect(sHud, &(SDL_Rect){40, 3, winw2-85, 13}, 0xDDa0b010);
    SDL_FillRect(sHud, &(SDL_Rect){winw2+60, 3, winw2-102, 13}, 0xDDa0b010);

    // pixel crosshair
    // setpixel(sHud, winw2, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2+1, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2-1, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2, winh2+1, 0xFFFFFF00);
    // setpixel(sHud, winw2, winh2-1, 0xFFFFFF00);
    // setpixel(sHud, winw2+2, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2-2, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2, winh2+2, 0xFFFFFF00);
    // setpixel(sHud, winw2, winh2-2, 0xFFFFFF00);
    // setpixel(sHud, winw2+3, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2-3, winh2, 0xFFFFFF00);
    // setpixel(sHud, winw2, winh2+3, 0xFFFFFF00);
    // setpixel(sHud, winw2, winh2-3, 0xFFFFFF00);

    // fps
    char tmp[16];
    sprintf(tmp, "%u", g_fps);
    SDL_FillRect(sHud, &(SDL_Rect){0, 19, lenText(tmp)+8, 19}, 0xCC000000);
    drawText(sHud, tmp, 4, 23, 2);
    // center hud
    const int top = winh2-(11*12);
    const int left = winw2-239;
    SDL_FillRect(sHud, &(SDL_Rect){winw2-255, top-5, 510, 280}, 0xBBa0b010);
    SDL_FillRect(sHud, &(SDL_Rect){winw2-250, top, 500, 270}, 0xCC000000);
    int a = drawText(sHud, "Voxel Paint", winw2-27, top+11, 3);
    a = drawText(sHud, appVersion, left+455, top+11, 4);
    a = drawText(sHud, "mrbid.github.io", left, top+11, 4);
    a = drawText(sHud, "WASD ", left, top+(11*3), 2);
    drawText(sHud, "Move around based on relative orientation to X and Y.", a, top+(11*3), 1);
    a = drawText(sHud, "SPACE", left, top+(11*4), 2);
    a = drawText(sHud, " + ", a, top+(11*4), 4);
    a = drawText(sHud, "L-SHIFT ", a, top+(11*4), 2);
    drawText(sHud, "Move up and down relative Z.", a, top+(11*4), 1);
    a = drawText(sHud, "Left Click", left, top+(11*5), 2);
    a = drawText(sHud, " or ", a, top+(11*5), 3);
    a = drawText(sHud, "R-SHIFT ", a, top+(11*5), 2);
    drawText(sHud, "Place node.", a, top+(11*5), 1);
    a = drawText(sHud, "Right Click", left, top+(11*6), 2);
    a = drawText(sHud, " or ", a, top+(11*6), 3);
    a = drawText(sHud, "R-CTRL ", a, top+(11*6), 2);
    drawText(sHud, "Delete node.", a, top+(11*6), 1);
    a = drawText(sHud, "E", left, top+(11*7), 2);
    a = drawText(sHud, " or ", a, top+(11*7), 3);
    a = drawText(sHud, "F", a, top+(11*7), 2);
    a = drawText(sHud, " or ", a, top+(11*7), 3);
    a = drawText(sHud, "Mouse4 ", a, top+(11*7), 2);
    drawText(sHud, "Toggle player fast speed on and off.", a, top+(11*7), 1);
    a = drawText(sHud, "1-7 ", left, top+(11*8), 2);
    drawText(sHud, "Change move speed for selected fast state.", a, top+(11*8), 1);
    a = drawText(sHud, "Middle Click", left, top+(11*9), 2);
    a = drawText(sHud, " or ", a, top+(11*9), 3);
    a = drawText(sHud, "Q ", a, top+(11*9), 2);
    drawText(sHud, "Clone texture of pointed node.", a, top+(11*9), 1);
    a = drawText(sHud, "X", left, top+(11*10), 2);
    a = drawText(sHud, " + ", a, top+(11*10), 4);
    a = drawText(sHud, "C", a, top+(11*10), 2);
    a = drawText(sHud, " or ", a, top+(11*10), 3);
    a = drawText(sHud, "Slash", a, top+(11*10), 2);
    a = drawText(sHud, " + ", a, top+(11*10), 4);
    a = drawText(sHud, "Quote ", a, top+(11*10), 2);
    drawText(sHud, "Change texture of pointed node.", a, top+(11*10), 1);
    a = drawText(sHud, "T ", left, top+(11*11), 2);
    drawText(sHud, "Resets player state to start.", a, top+(11*11), 1);
    a = drawText(sHud, "P ", left, top+(11*12), 2);
    a = drawText(sHud, "Toggle pitch lock.", a, top+(11*12), 1);
    a = drawText(sHud, " G ", a, top+(11*12), 2);
    drawText(sHud, "Toggle gravity on and off.", a, top+(11*12), 1);
    a = drawText(sHud, "R ", left, top+(11*13), 2);
    drawText(sHud, "Places node at your current position.", a, top+(11*13), 1);
    a = drawText(sHud, "F3 ", left, top+(11*14), 2);
    drawText(sHud, "Save. Will auto save on exit. Backup made if idle for 3 mins.", a, top+(11*14), 1);
    a = drawText(sHud, "F8 ", left, top+(11*15), 2);
    drawText(sHud, "Load. Will erase what you have done since the last save.", a, top+(11*15), 1);
    a = drawText(sHud, "V ", left, top+(11*16), 2);
    drawText(sHud, "Pastes selected nodes to pointed position.", a, top+(11*16), 1);
    a = drawText(sHud, "Arrow Keys ", left, top+(11*17), 2);
    drawText(sHud, "can be used to move the view around.", a, top+(11*17), 1);
    a = drawText(sHud, "ESCAPE ", left, top+(11*18), 3);
    drawText(sHud, "Release mouse focus.", a, top+(11*18), 1);
    a = drawText(sHud, "To multiselect=", left, top+(11*20), 3);
    a = drawText(sHud, " click and drag with ", a, top+(11*20), 1);
    a = drawText(sHud, "Mouse 3", a, top+(11*20), 2);
    a = drawText(sHud, " or ", a, top+(11*20), 1);
    a = drawText(sHud, "Q", a, top+(11*20), 2);
    a = drawText(sHud, ". Use ", a, top+(11*20), 1);
    a = drawText(sHud, "B", a, top+(11*20), 2);
    a = drawText(sHud, " to fill the selected area.", a, top+(11*20), 1);
    a = drawText(sHud, "Use ", left, top+(11*21), 1);
    a = drawText(sHud, "N", a, top+(11*21), 2);
    a = drawText(sHud, " to delete area.", a, top+(11*21), 1);
    a = drawText(sHud, " Middle Scroll ", a, top+(11*21), 2);
    a = drawText(sHud, "or ", a, top+(11*21), 3);
    a = drawText(sHud, "X", a, top+(11*21), 2);
    a = drawText(sHud, " + ", a, top+(11*21), 4);
    a = drawText(sHud, "C", a, top+(11*21), 2);
    a = drawText(sHud, " to change texture.", a, top+(11*21), 1);
    drawText(sHud, "Check the console output for information about how to customize the tiles.", left, top+(11*23), 4);
    // flip the new hud to gpu
    flipHud();
}

//*************************************
// Process Entry Point
//*************************************
int main(int argc, char** argv)
{
//*************************************
// setup render context / window
//*************************************
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0)
    {
        printf("ERROR: SDL_Init(): %s\n", SDL_GetError());
        return 1;
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    wnd = SDL_CreateWindow(appTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winw, winh, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if(wnd == NULL)
    {
        printf("ERROR: SDL_CreateWindow(): %s\n", SDL_GetError());
        return 1;
    }
    SDL_GL_SetSwapInterval(1);
    glc = SDL_GL_CreateContext(wnd);
    if(glc == NULL)
    {
        printf("ERROR: SDL_GL_CreateContext(): %s\n", SDL_GetError());
        return 1;
    }

    // callback for custom decor
    SDL_SetWindowHitTest(wnd, hitTest, NULL);

    // set icon
    s_icon = surfaceFromData((Uint32*)&icon, 16, 16);
    SDL_SetWindowIcon(wnd, s_icon);

    // seed random
    srand(time(0));
    srandf(time(0));

    // get paths
    basedir = SDL_GetBasePath();
    appdir = SDL_GetPrefPath("voxdsp", "voxelpaint");

    // print info
    printf("----\n");
    printAttrib(SDL_GL_DOUBLEBUFFER, "GL_DOUBLEBUFFER");
    printAttrib(SDL_GL_DEPTH_SIZE, "GL_DEPTH_SIZE");
    printAttrib(SDL_GL_RED_SIZE, "GL_RED_SIZE");
    printAttrib(SDL_GL_GREEN_SIZE, "GL_GREEN_SIZE");
    printAttrib(SDL_GL_BLUE_SIZE, "GL_BLUE_SIZE");
    printAttrib(SDL_GL_ALPHA_SIZE, "GL_ALPHA_SIZE");
    printAttrib(SDL_GL_BUFFER_SIZE, "GL_BUFFER_SIZE");
    printAttrib(SDL_GL_STENCIL_SIZE, "GL_STENCIL_SIZE");
    printAttrib(SDL_GL_ACCUM_RED_SIZE, "GL_ACCUM_RED_SIZE");
    printAttrib(SDL_GL_ACCUM_GREEN_SIZE, "GL_ACCUM_GREEN_SIZE");
    printAttrib(SDL_GL_ACCUM_BLUE_SIZE, "GL_ACCUM_BLUE_SIZE");
    printAttrib(SDL_GL_ACCUM_ALPHA_SIZE, "GL_ACCUM_ALPHA_SIZE");
    printAttrib(SDL_GL_STEREO, "GL_STEREO");
    printAttrib(SDL_GL_MULTISAMPLEBUFFERS, "GL_MULTISAMPLEBUFFERS");
    printAttrib(SDL_GL_MULTISAMPLESAMPLES, "GL_MULTISAMPLESAMPLES");
    printAttrib(SDL_GL_ACCELERATED_VISUAL, "GL_ACCELERATED_VISUAL");
    printAttrib(SDL_GL_RETAINED_BACKING, "GL_RETAINED_BACKING");
    printAttrib(SDL_GL_CONTEXT_MAJOR_VERSION, "GL_CONTEXT_MAJOR_VERSION");
    printAttrib(SDL_GL_CONTEXT_MINOR_VERSION, "GL_CONTEXT_MINOR_VERSION");
    printAttrib(SDL_GL_CONTEXT_FLAGS, "GL_CONTEXT_FLAGS");
    printAttrib(SDL_GL_CONTEXT_PROFILE_MASK, "GL_CONTEXT_PROFILE_MASK");
    printAttrib(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, "GL_SHARE_WITH_CURRENT_CONTEXT");
    printAttrib(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, "GL_FRAMEBUFFER_SRGB_CAPABLE");
    printAttrib(SDL_GL_CONTEXT_RELEASE_BEHAVIOR, "GL_CONTEXT_RELEASE_BEHAVIOR");
    printAttrib(SDL_GL_CONTEXT_EGL, "GL_CONTEXT_EGL");
    printf("----\n");
    SDL_version compiled;
    SDL_version linked;
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);
    printf("Compiled against SDL version %u.%u.%u.\n", compiled.major, compiled.minor, compiled.patch);
    printf("Linked against SDL version %u.%u.%u.\n", linked.major, linked.minor, linked.patch);
    printf("----\n");
    printf("currentPath: %s\n", basedir);
    printf("dataPath:    %s\n", appdir);
    printf("exportPath:  %s/EXPORTS/VoxelPaint_exports/\n", getenv("HOME"));
    printf("----\n");
    printf(">>> Voxel Paint <<<\n");
    printf("----\n");
    printf("James William Fletcher (github.com/mrbid)\n");
    printf("----\n\n");
    printf("Mouse locks when you click on the game window, press ESCAPE or TAB to unlock the mouse.\n\n");
    printf("W,A,S,D = Move around based on relative orientation to X and Y.\n");
    printf("SPACE + L-SHIFT = Move up and down relative Z.\n");
    printf("Left Click / R-SHIFT = Place node.\n");
    printf("Right Click / R-CTRL = Delete node.\n");
    printf("Q / Middle Click = Clone texture of pointed node.\n");
    printf("R = Places node at your current position.\n");
    printf("E / F / Mouse4 = Toggle player fast speed on and off.\n");
    printf("1-7 = Change move speed for selected fast state.\n");
    printf("X + C / Slash + Quote = Change texture of pointed node.\n");
    printf("T = Resets player state to start.\n");
    printf("G = Gravity on/off.\n");
    printf("P = Toggle pitch lock.\n");
    printf("F3 = Save. (auto saves on exit, backup made if idle for 3 mins.)\n");
    printf("F8 = Load. (will erase what you have done since the last save)\n");
#ifdef __linux__
    printf("F10 = Export the VoxelPaint data to a zip file in $HOME/EXPORTS.\n");
#endif
    printf("\n- Multi Selections\n");
    printf("--------------------------------------------------\n");
    printf("Middle Mouse Click (or Q and drag) to select area.\n");
    printf("--------------------------------------------------\n");
    printf("V = Copies the selected nodes to the currently pointed position,\n    the point you started the selection from is the point you will\n    copy from at the new pointed location.\n");
    printf("B = Fill selected nodes with selected color.\nN = Delete selected nodes.\n");
    printf("--------------------------------------------\n");
    printf("\n* Arrow Keys can be used to move the view around.\n");
    printf("* Your state is automatically saved on exit.\n");
    printf("* You can customize the 17 block tileset,\n  in your dataPath(%s)\n  you will find a tiles.ppm image file, edit this file and\n  save it as a PPM with a `P6 272 16 255` header.\n  ! Krita (https://krita.org) or KolourPaint can edit PPM files.\n", appdir);
    printf("* You can change the mouse sensitivity by passing the new\n  sensitivity as the 1st command line parameter default is\n  0.003 `./vox 0.003`.\n");
    printf("\n----\n");

//*************************************
// prepare data loading
//*************************************
    // try to read custom tiles
    char fp[256];
    sprintf(fp, "%s/tiles.ppm", appdir);
    FILE* fc = fopen(fp, "rb");
    if(fc != NULL)
    {
        fseek(fc, 14, SEEK_SET);
        if(fread(&tiles, sizeof(unsigned char), 13056, fc) != 13056)
        {
            char tmp[16];
            timestamp(tmp);
            printf("[%s] Reading custom tiles.ppm failed, incorrect file size.\n", tmp);
        }
        fclose(fc);
    }

//*************************************
// projection & compile & link shader program
//*************************************
    makeVoxel();
    makeHud();
    doPerspective();

//*************************************
// configure render options
//*************************************
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(4.f);
#ifdef SKYBLUE
    glClearColor(0.3f, 0.745f, 0.8863f, 0.f);
#else
    glClearColor(0.f, 0.f, 0.f, 0.f);
#endif

//*************************************
// init stuff
//*************************************

    // center voxel
    memset(g.voxels, 0x00, sizeof(vec)*max_voxels);
    g.voxels[0] = (vec){0.f, 0.f, 0.f, 13.f};
    g.num_voxels = 1;

    // load states
#ifdef NO_COMPRESSION
    if(loadState() == 0 && loadOldState() == 0)
#else
    if(loadState() == 0 && loadUncompressedState() == 0 && loadOldState() == 0)
#endif
    {
        // default state
        defaultState(0);

        // write ppm of tiles to appdir
        if(fc == NULL)
        {
            FILE* f = fopen(fp, "wb");
            if(f != NULL)
            {
                fprintf(f, "P6 272 16 255 ");
                fwrite(tiles, sizeof(unsigned char), 13056, f);
                fclose(f);
            }
        }

        // done
        char tmp[16];
        timestamp(tmp);
        printf("[%s] New world created.\n", tmp);
    }
    if(g.num_voxels == 0){g.num_voxels = 1;}

    // argv mouse sensitivity
    if(argc >= 2){g.sens = atof(argv[1]);}

    // make sure voxel data is grid-aligned
    if(argc == 3)
    {
        for(int i = 0; i < g.num_voxels; i++)
        {
            if(g.voxels[i].w < 0.f){continue;}
            g.voxels[i].x = roundf(g.voxels[i].x);
            g.voxels[i].y = roundf(g.voxels[i].y);
            g.voxels[i].z = roundf(g.voxels[i].z);
        }
    }

    // hud buffer
    sHud = SDL_RGBA32Surface(winw, winh);
    drawHud();
    hudmap = esLoadTextureA(winw, winh, sHud->pixels, 0);

//*************************************
// execute update / render loop
//*************************************
    t = fTime();
    uint fps = 0;
    float ft = t+3.f;
    while(1)
    {
        if(t > ft)
        {
            g_fps = fps/3;
#ifdef VERBOSE
            char tmp[16];
            timestamp(tmp);
            printf("[%s] %u fps, %u voxels\n", tmp, g_fps, g.num_voxels);
#endif
            if(focus_mouse == 0 && winw > 500 && winh > 280)
                drawHud();
            fps = 0;
            ft = t+3.f;
        }
        main_loop();
        fps++;
    }
    return 0;
}
