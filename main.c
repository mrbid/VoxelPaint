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
#define forceinline __attribute__((always_inline)) inline

//*************************************
// globals
//*************************************
const char appTitle[] = "Voxel Paint";
const char appVersion[] = "v1.7";
char *basedir, *appdir;
SDL_Window* wnd;
SDL_GLContext glc;
SDL_Surface* s_icon = NULL;
int winw = 1024, winh = 768;
int winw2 = 512, winh2 = 384;
float ww, wh;
float aspect, t = 0.f;
uint ks[10] = {0};      // keystate
uint focus_mouse = 0;   // mouse lock
float ddist = 460.f;    // view distance
float ddist2 = 460.f*460.f;
vec ipp;                // inverse player position
vec look_dir;           // camera look direction
int lray = 0;           // pointed at node index
float ptt = 0.f;        // place timing trigger (for repeat place)
float dtt = 0.f;        // delete timing trigger (for repeat delete)
uint fks = 0;           // F-Key state (fast mode toggle)

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
    uint grav;  // gravity on/off toggle
    uint num_voxels;
    vec voxels[max_voxels]; // x,y,z,w (w = texture_id)
}
game_state;
game_state g; // ~67mb

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
    void saveState()
    {
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.db2", appdir);
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
    void saveState()
    {
    #ifdef __linux__
        setlocale(LC_NUMERIC, "");
        const uint64_t st = microtime();
    #endif
        char file[256];
        sprintf(file, "%sworld.gz", appdir);
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

    if(g.pb.w == -1){return 0;}

    for(uint i = 0; i < g.num_voxels; i++)
    {
        if(g.voxels[i].w < 0.f)
        {
            g.voxels[i] = g.pb;
            g.voxels[i].w = g.st;
            return 1;
        }
    }
    if(g.num_voxels < max_voxels)
    {
        g.voxels[g.num_voxels] = g.pb;
        g.voxels[g.num_voxels].w = g.st;
        g.num_voxels++;
        return 1;
    }
    return 0;
}

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
    if(winw > 590 && winh > 250)
    {
        SDL_FreeSurface(sHud);
        sHud = SDL_RGBA32Surface(winw, winh);
        drawHud();
        hudmap = esLoadTextureA(winw, winh, sHud->pixels, 0);
    }
    ww = (float)winw;
    wh = (float)winh;
    mIdent(&projection);
    mPerspective(&projection, 60.0f, ww / wh, 0.01f, ddist);
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
void line(SDL_Surface *surface, Uint32 x0, Uint32 y0, Uint32 x1, Uint32 y1, Uint32 colour)
{
    const int dx = abs((Sint32)x1 - (Sint32)x0), sx = x0 < x1 ? 1 : -1;
    const int dy = abs((Sint32)y1 - (Sint32)y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;
    while(1)
    {
        setpixel(surface, x0, y0, colour);
        if(x0 == x1 && y0 == y1){break;}
        e2 = err;
        if(e2 > -dx){err -= dy; x0 += sx;}
        if(e2 < dy){err += dx; y0 += sy;}
    }
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
        if(s[i] == 'A'){     SDL_BlitSurface(font, &(SDL_Rect){0,0,7,9}, o, &dr); dr.x += 7+m;}
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

//*************************************
// update & render
//*************************************
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
    static int mx=0, my=0, lx=0, ly=0, md=0;
    static float idle = 0.f;

    // if user is idle for 3 minutes, save.
    if(idle != 0.f && t-idle > 180.f)
    {
        saveState();
        idle = 0.f; // so we only save once
        // on input a new idle is set, and a
        // count-down for a new save begins.
    }
    
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
            {
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
                else if(event.key.keysym.sym == SDLK_ESCAPE) // unlock mouse focus
                {
                    focus_mouse = 0;
                    SDL_ShowCursor(1);
                }
                else if(event.key.keysym.sym == SDLK_q) // clone pointed voxel texture
                {
                    traceViewPath(0);
                    if(lray > -1){g.st = g.voxels[lray].w;}
                }
                else if(event.key.keysym.sym == SDLK_SLASH || event.key.keysym.sym == SDLK_x) // - change selected node
                {
                    traceViewPath(0);
                    if(lray > -1)
                    {
                        g.st = g.voxels[lray].w - 1.f;
                        if(g.st < 0.f){g.st = 16.f;}
                        g.voxels[lray].w = g.st;
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
                else if(event.key.keysym.sym == SDLK_r || event.key.keysym.sym == SDLK_g) // gravity toggle
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
                else if(event.key.keysym.sym == SDLK_F3)
                {
                    saveState();
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
                    sprintf(cmd, "%s/Documents", getenv("HOME"));
                    mkdir(cmd, 0755);
                    sprintf(cmd, "%s/Documents/VoxelPaint_exports", getenv("HOME"));
                    mkdir(cmd, 0755);
                    char tmp2[16];
                    timestamp(tmp2);
                    if(fileExist("/usr/bin/7z") == 1)
                    {
                        sprintf(cmd, "7z a -y -bsp0 -bso0 -r %s/Documents/VoxelPaint_exports/voxelpaint_%s_%u.7z %s/*", getenv("HOME"), tmp, g.num_voxels, appdir);
                        if(system(cmd) < 0){printf("system() failed: %s\n", cmd);}
                        printf("[%s] Exported data to: %s/Documents/VoxelPaint_exports/voxelpaint_%s_%u.7z\n", tmp2, getenv("HOME"), tmp, g.num_voxels);
                    }
                    else if(fileExist("/usr/bin/zip") == 1)
                    {
                        sprintf(cmd, "zip -jq9 %s/Documents/VoxelPaint_exports/voxelpaint_%s_%u.zip %s/world.db %s/world.db2 %s/world.gz %s/tiles.ppm", getenv("HOME"), tmp, g.num_voxels, appdir, appdir, appdir, appdir);
                        if(system(cmd) < 0){printf("system() failed: %s\n", cmd);}
                        printf("[%s] Exported data to: %s/Documents/VoxelPaint_exports/voxelpaint_%s_%u.zip\n", tmp2, getenv("HOME"), tmp, g.num_voxels);
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
                idle = t;
            }
            break;

            case SDL_MOUSEWHEEL: // change selected node
            {
                if(focus_mouse == 0){break;}

                traceViewPath(0);
                if(lray > -1)
                {
                    if(event.wheel.y > 0)
                    {
                        g.st = g.voxels[lray].w + 1.f;
                        if(g.st > 16.f){g.st = 0.f;}
                    }
                    else if(event.wheel.y < 0)
                    {
                        g.st = g.voxels[lray].w - 1.f;
                        if(g.st < 0.f){g.st = 16.f;}
                    }

                    g.voxels[lray].w = g.st;
                    idle = t;
                }
                else
                {
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
                }
            }
            break;

            case SDL_MOUSEMOTION:
            {
                if(focus_mouse == 0){break;}
                mx = event.motion.x;
                my = event.motion.y;
                idle = t;
            }
            break;

            case SDL_MOUSEBUTTONUP:
            {
                if(event.button.button == SDL_BUTTON_LEFT){ptt = 0.f;}
                else if(event.button.button == SDL_BUTTON_RIGHT){dtt = 0.f;}
                md = 0;
                idle = t;
            }
            break;

            case SDL_MOUSEBUTTONDOWN:
            {
                lx = event.button.x;
                ly = event.button.y;
                mx = event.button.x;
                my = event.button.y;

                if(focus_mouse == 0) // lock mouse focus on every mouse input to the window
                {
                    SDL_ShowCursor(0);
                    focus_mouse = 1;
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
                    if(lray > -1){g.st = g.voxels[lray].w;}
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

            case SDL_WINDOWEVENT:
            {
                if(event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    winw = event.window.data1;
                    winh = event.window.data2;
                    winw2 = winw/2;
                    winh2 = winh/2;
                    doPerspective();
                }
            }
            break;

            case SDL_QUIT:
            {
                SDL_HideWindow(wnd);
                saveState();
                SDL_FreeSurface(s_icon);
                SDL_FreeSurface(sHud);
                SDL_GL_DeleteContext(glc);
                SDL_DestroyWindow(wnd);
                SDL_Quit();
                exit(0);
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

        if(g.grav == 1)
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
            mGetViewY(&vdc, view);
            vec m;
            vMulS(&m, vdc, g.ms * dt);
            vSub(&g.pp, g.pp, m);
        }
        else if(ks[9] == 1) // SPACE (up)
        {
            vec vdc;
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
        const float xd = lx-mx;
        const float yd = ly-my;
        if(xd != 0 || yd != 0)
        {
            g.xrot += xd*g.sens;
            g.yrot += yd*g.sens;
        
            if(g.yrot > 3.f)
                g.yrot = 3.f;
            if(g.yrot < 0.f)
                g.yrot = 0.f;
            
            lx = winw2, ly = winh2;
            SDL_WarpMouseInWindow(wnd, lx, ly);
        }
    }

    mIdent(&view);
    mRotate(&view, g.yrot, 1.f, 0.f, 0.f);
    mRotate(&view, g.xrot, 0.f, 0.f, 1.f);
    mTranslate(&view, g.pp.x, g.pp.y, g.pp.z);

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
    for(int j = 0; j < g.num_voxels; j++)
    {
        if(g.voxels[j].w < 0.f || 
            vDistSq(ipp, g.voxels[j]) >= ddist2 ||
            insideFrustum(g.voxels[j].x, g.voxels[j].y, g.voxels[j].z) == 0){continue;}

        glUniform4f(voxel_id, g.voxels[j].x, g.voxels[j].y, g.voxels[j].z, g.voxels[j].w);
        glDrawElements(GL_TRIANGLES, voxel_numind, GL_UNSIGNED_BYTE, 0);
    }

    // crosshair
    mGetViewZ(&look_dir, view);
    const float nx = ipp.x+(look_dir.x*130.f), ny = ipp.y+(look_dir.y*130.f), nz = ipp.z+(look_dir.z*130.f);
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
    SDL_FillRect(sHud, &sHud->clip_rect, 0x00000000);

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
    
    const int winw24 = winw2/4;
    const int wn = winw2-(winw24);
    const int hn = winh2-(winw24);
    const int top = winh2-(11*10);
    int left = (winw2-wn)+11;
    if(wn > 250){left += wn-250;}
    int right = wn*2;
    if(right > 500){right = 500;}
    SDL_FillRect(sHud, &(SDL_Rect){left-11, top, right, 230}, 0xCC000000);
    int a = drawText(sHud, "Voxel Paint", winw2-25, top+11, 3);
    a = drawText(sHud, appVersion, left+right-45, top+11, 4);
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
    a = drawText(sHud, "Q", left, top+(11*9), 2);
    a = drawText(sHud, " or ", a, top+(11*9), 3);
    a = drawText(sHud, "Middle Click ", a, top+(11*9), 2);
    drawText(sHud, "Clone texture of pointed node.", a, top+(11*9), 1);
    a = drawText(sHud, "Mouse Scroll", left, top+(11*10), 2);
    a = drawText(sHud, " or ", a, top+(11*10), 3);
    a = drawText(sHud, "Slash", a, top+(11*10), 2);
    a = drawText(sHud, " + ", a, top+(11*10), 4);
    a = drawText(sHud, "Quote", a, top+(11*10), 2);
    a = drawText(sHud, " or ", a, top+(11*10), 3);
    a = drawText(sHud, "X", a, top+(11*10), 2);
    a = drawText(sHud, " + ", a, top+(11*10), 4);
    a = drawText(sHud, "C ", a, top+(11*10), 2);
    drawText(sHud, "Change texture of pointed node.", a, top+(11*10), 1);
    a = drawText(sHud, "T ", left, top+(11*11), 2);
    drawText(sHud, "Resets view and position matrix.", a, top+(11*11), 1);
    a = drawText(sHud, "R or G ", left, top+(11*12), 2);
    drawText(sHud, "Gravity on/off.", a, top+(11*12), 1);
    a = drawText(sHud, "F3 ", left, top+(11*13), 2);
    drawText(sHud, "Save. (auto saves on exit or idle for more than 3 minutes)", a, top+(11*13), 1);
    a = drawText(sHud, "F8 ", left, top+(11*14), 2);
    drawText(sHud, "Load. (will erase what you have done since the last save)", a, top+(11*14), 1);
#ifdef __linux__
    a = drawText(sHud, "F10 ", left, top+(11*15), 2);
    drawText(sHud, "Export the VoxelPaint data to a zip file in $HOME/Documents.", a, top+(11*15), 1);
#endif
    a = drawText(sHud, "Arrow Keys ", left, top+(11*16), 2);
    drawText(sHud, "can be used to move the view around.", a, top+(11*16), 1);
    a = drawText(sHud, "ESCAPE ", left, top+(11*17), 3);
    drawText(sHud, "Release mouse focus.", a, top+(11*17), 1);
    drawText(sHud, "Check the console output for information about how to customize the tiles.", left, top+(11*19), 3);
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
    wnd = SDL_CreateWindow(appTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winw, winh, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
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
    printAttrib(SDL_GL_DOUBLEBUFFER, "GL_DOUBLEBUFFER");
    printAttrib(SDL_GL_DEPTH_SIZE, "GL_DEPTH_SIZE");
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
    printf("exportPath:  %s/Documents/VoxelPaint_exports/\n", getenv("HOME"));
    printf("----\n");
    printf(">>> Voxel Paint <<<\n\n");
    printf("James William Fletcher (github.com/mrbid)\n\n");
    printf("Mouse locks when you click on the game window, press ESCAPE to unlock the mouse.\n\n");
    printf("W,A,S,D = Move around based on relative orientation to X and Y.\n");
    printf("SPACE + L-SHIFT = Move up and down relative Z.\n");
    printf("Left Click / R-SHIFT = Place node.\n");
    printf("Right Click / R-CTRL = Delete node.\n");
    printf("E / F / Mouse4 = Toggle player fast speed on and off.\n");
    printf("1-7 = Change move speed for selected fast state.\n");
    printf("Q / Middle Click = Clone texture of pointed node.\n");
    printf("Mouse Scroll / Slash + Quote / X + C = Change texture of pointed node.\n");
    printf("T = Resets view and position matrix.\n");
    printf("R / G = Gravity on/off.\n");
    printf("F3 = Save. (auto saves on exit or idle for more than 3 minutes)\n");
    printf("F8 = Load. (will erase what you have done since the last save)\n");
#ifdef __linux__
    printf("F10 = Export the VoxelPaint data to a zip file in $HOME/Documents.\n");
#endif
    printf("\n* Arrow Keys can be used to move the view around.\n");
    printf("* Your state is automatically saved on exit.\n");
    printf("* You can customize the 17 block tileset,\n  in your dataPath(%s)\n  you will find a tiles.ppm image file, edit this file and\n  save it as a ppm with a `P6 272 16 255` header.\n  ! Krita (https://krita.org) can edit ppm files.\n", appdir);
    printf("----\n");

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
    doPerspective();
    makeVoxel();
    makeHud();

//*************************************
// configure render options
//*************************************
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
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
            if(g.voxels[i].w < 0){continue;}
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
#ifdef VERBOSE
    t = fTime();
    uint fps = 0;
    float ft = t+3.f;
#endif
    while(1)
    {
#ifdef VERBOSE
        if(t > ft)
        {
            char tmp[16];
            timestamp(tmp);
            printf("[%s] %u fps, %u voxels\n", tmp, fps/3, g.num_voxels);
            //printf("%f %f %f %f %f %f %f %f %f %f %u\n", g.xrot, g.yrot, g.pp.x, g.pp.y, g.pp.z, g.pp.w, g.ms, g.st, g.lms, g.cms, g.grav);
            fps = 0;
            ft = t+3.f;
        }
#endif
        main_loop();
#ifdef VERBOSE
        fps++;
#endif
    }
    return 0;
}
