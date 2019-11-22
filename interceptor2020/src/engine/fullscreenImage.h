struct FullscreenImageStruct {
    unsigned char tilesBase;
    unsigned char tilesLength;
    unsigned char *tiles;
    unsigned char *ptiles;
};
typedef struct FullscreenImageStruct FullscreenImage;

void FullscreenImage_initialize(FullscreenImage *fullscreenImage, 
                                 unsigned char tilesBase, 
                                 unsigned char tilesLength, 
                                 unsigned char *tiles, 
                                 unsigned char *ptiles) {
    fullscreenImage->tilesBase = tilesBase;
    fullscreenImage->tilesLength = tilesLength;
    fullscreenImage->tiles = tiles;
    fullscreenImage->ptiles = ptiles;
}
