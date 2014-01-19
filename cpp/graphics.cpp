#include "headers/graphics.h" 

void raycast(Image& img, Player player, Map& map){ //Remplit l'image avec le sol et les murs
    float angle;
    float height; //Hauteur du mur
    for(int j = 0; j < W; ++j){ //On parcoure les colonnes de pixel
        angle = player.yaw+FOV*j/W-FOV/2;
        height = H_WALLS/map.findWall(player, angle);
        
        for(int i = 0; i < max(0, int(H/2-height/2)); ++i)
            img.set(i, j, SKY);
        for(int i = max(0, int(H/2-height/2)); i < min(int(H/2+height/2), H); ++i)
            img.set(i, j, WALL);
        for(int i = min(int(H/2+height/2), H); i < H; ++i)
            img.set(i, j, FLOOR);
    }
}

void minimap(Player player, Map& map){

	int w=W*A_MINIMAP/100;
	int h=W*A_MINIMAP/100;
    
    fillRect(0, 0, w, h, WHITE);
    fillCircle(player.pos.x*w/map.w, player.pos.y*h/map.h, 3, BLUE);
    drawLine(player.pos.x*w/map.w, player.pos.y*h/map.h, player.pos.x*w/map.w+int(INFINITE*cos(player.yaw)), player.pos.y*h/map.h+int(INFINITE*sin(player.yaw)), GREEN, 2);
    drawLine(player.pos.x*w/map.w, player.pos.y*h/map.h, player.pos.x*w/map.w+int(INFINITE*cos(player.yaw-FOV/2)), player.pos.y*h/map.h+int(INFINITE*sin(player.yaw-FOV/2)), GREEN, 2);
    drawLine(player.pos.x*w/map.w, player.pos.y*h/map.h, player.pos.x*w/map.w+int(INFINITE*cos(player.yaw+FOV/2)), player.pos.y*h/map.h+int(INFINITE*sin(player.yaw+FOV/2)), GREEN, 2);
    
    for(int i = 0; i < map.nbEdge; ++i){
        if(map.edg[i].type == 1)
            drawLine(map.edg[i].A.x*w/map.w, map.edg[i].A.y*h/map.h, map.edg[i].B.x*w/map.w, map.edg[i].B.y*h/map.h, RED, 2);
        else
            drawLine(map.edg[i].A.x*w/map.w, map.edg[i].A.y*h/map.h, map.edg[i].B.x*w/map.w, map.edg[i].B.y*h/map.h, BLACK, 1);
    }
}

void graphics(Image& img, Player player, Map& map){
    raycast(img, player, map);
}
