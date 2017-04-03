/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Please fill in the following team struct
 */
team_t team = {
    "we_perf",			/* Team name */

    "Christian Leishman",		/* First member full name */
    "johncleishman@gmail.com",		/* First member email address */

    "Zachary Halvorsen",		  /* Second member full name (leave blank if none) */
    "ztoked@gmail.com"		  /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/*
 * naive_rotate - The naive baseline version of rotate
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
	   for (j = 0; j < dim; j++)
	      dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/*
 * TODO
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst)
{
    int i, j, k;
    int num_pix = dim*dim;

    dst += num_pix - dim;
    for (i = 0; i < dim; i += 32) {
        for (j = 0; j < dim; ++j) {
            for(k = 0; k < 31; ++k){
                *(dst + k) = *src;
                src += dim;
            }
            *(dst + 31) = *src;

            dst -= dim;
            src -= (dim*31) - 1;
        }
        dst += 32 + num_pix;
        src += dim*31;
    }
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_functions()
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate, rotate_descr);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

typedef struct{
    int red;
    int green;
    int blue;
} pixel_int;

int dimension;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/*
 * initialize_pixel_sum - Initializes all fields of sum to 0
 */
static void initialize_pixel_sum(pixel_sum *sum)
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/*
 * accumulate_sum - Accumulates field values of p in corresponding
 * fields of sum
 */
static void accumulate_sum(pixel_sum *sum, pixel p)
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
}

/*
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum)
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
}

/*
 * avg - Returns averaged pixel value at (i,j)
 */
static pixel avg(int dim, int i, int j, pixel *src)
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++)
        for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++)
            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * TODO
 * smooth - Your current working version of smooth.
 * IMPORTANT: This is the version you will be graded on
 */

static void reset_cache(pixel_int *cache){
    cache->red = cache->green = cache->blue = 0;
}

static void get_pixel(pixel_int *cache, pixel *src){
    cache->red += src->red;
    cache->green += src->green;
    cache->blue += src->blue;
}

static void div_result(pixel *result, pixel_int *cache, int div){
    result->red   = cache->red/div;
    result->green = cache->green/div;
    result->blue  = cache->blue/div;
}

static void up(pixel *src){
    src-=dimension;
}

static void down(pixel *src){
    src+=dimension;
}

static void left(pixel *src){
    src--;
}

static void right(pixel *src){
    src++;
}

 static void get_corners(int dim, pixel *src, pixel *dst){
    pixel_int cache;
    pixel result;

    // TOPLEFT
    reset_cache(&cache);
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src--;

    div_result(&result, &cache, 4);
    *dst = result;
    dst += dim-1;

    // top-right
    reset_cache(&cache);
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src+=1+dim*(dim-3);

    div_result(&result, &cache, 4);
    *dst = result;
    dst+=1+dim*(dim-2);

    // bottom-left
    reset_cache(&cache);
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src-=dim;
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src+=dim-1;

    div_result(&result, &cache, 4);
    *dst = result;
    dst+=dim-1;

    // bottom-right
    reset_cache(&cache);
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);

    div_result(&result, &cache, 4);
    *dst = result;
}

static void get_top_border(int pos,int dim,pixel *src,pixel *dst){
    pixel_int cache;
    pixel result;
    reset_cache(&cache);

    src += pos;
    dst += pos;

    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src-=dim;
    get_pixel(&cache, src);

    div_result(&result, &cache, 6);
    *dst = result;
}

static void get_left_border(int pos,int dim,pixel *src,pixel *dst){
    pixel_int cache;
    pixel result;
    reset_cache(&cache);

    src += pos;
    dst += pos;

    get_pixel(&cache, src);
    src-=dim;
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);

    div_result(&result, &cache, 6);
    *dst = result;
}

static void get_bottom_border(int pos,int dim,pixel *src,pixel *dst){
    pixel_int cache;
    pixel result;
    reset_cache(&cache);

    src += pos;
    dst += pos;

    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);
    src-=dim;
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);

    div_result(&result, &cache, 6);
    *dst = result;
}

static void get_right_border(int pos,int dim,pixel *src,pixel *dst){
    pixel_int cache;
    pixel result;
    reset_cache(&cache);

    src += pos;
    dst += pos;

    get_pixel(&cache, src);
    src-=dim;
    get_pixel(&cache, src);
    src--;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src+=dim;
    get_pixel(&cache, src);
    src++;
    get_pixel(&cache, src);

    div_result(&result, &cache, 6);
    *dst = result;
}

char smooth_descr[] = "smooth: Developing new algo";
void smooth(int dim, pixel *src, pixel *dst){
    int i,j;
    pixel_int top_left;
    pixel_int top_right;
    pixel_int bot_left;
    pixel_int bot_right;

    dimension = dim;

    get_corners(dim,src,dst);

    for(j = 1;j < dim-1;j++){
        get_top_border(j,dim,src,dst);
        get_bottom_border((dim-1)*dim+j,dim,src,dst);
    }

    for(i = 1;i < dim-1;i++){
        get_left_border(i*dim,dim,src,dst);
        get_right_border(i*dim+dim-1,dim,src,dst);
    }

    dst+=1+dim;
    src+=1+dim;

    for(i = 1;i < dim-1; i+=2){
        for(j = 1;j < dim-1;j+=2){
            top_left.red = src->red;
            top_left.green = src->green;
            top_left.blue = src->blue;
            src++;
            get_pixel(&top_left, src);
            src+=dim;
            get_pixel(&top_left, src);
            src--;
            get_pixel(&top_left, src);
            src--;
            top_right = bot_left = bot_right = top_left;
            get_pixel(&top_left, src);
            src-=dim;
            get_pixel(&top_left, src);
            bot_left = top_left;
            src-=dim;
            get_pixel(&top_left, src);
            src++;
            get_pixel(&top_left, src);
            get_pixel(&top_right, src);
            src++;
            get_pixel(&top_left, src);
            get_pixel(&top_right, src);
            src++;
            get_pixel(&top_right, src);
            src+=dim;
            get_pixel(&bot_right, src);
            get_pixel(&top_right, src);
            src+=dim;
            get_pixel(&bot_right, src);
            get_pixel(&top_right, src);
            src+=dim;
            get_pixel(&bot_right, src);
            src--;
            get_pixel(&bot_right, src);
            get_pixel(&bot_left, src);
            src--;
            get_pixel(&bot_right, src);
            get_pixel(&bot_left, src);
            src--;
            get_pixel(&bot_left, src);
            src-=2*dim-3;

            div_result(dst, &top_left, 9);
            dst+=dim;
            div_result(dst, &bot_left, 9);
            dst++;
            div_result(dst, &bot_right, 9);
            dst-=dim;
            div_result(dst, &top_right, 9);
            dst++;
            }

        src+=dim+2;
        dst+=dim+2;
    }

}

/*********************************************************************
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}
