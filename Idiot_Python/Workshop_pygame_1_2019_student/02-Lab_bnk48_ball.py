# Lab_BNK48 (SCORE 2%)

import pygame as pg

# TO DO 1 : กำหนด width : 1000 , height : 600 และ FPS : 60
width = 1000 
height = 600 
FPS = 60 

# TO DO 2 : กำหนดค่าสีดังนี้ pink : (197,142,195) , white : (255,255,255)
pink = (197,142,195)
white = (255,255,255)

# TO DO 3 : กำหนดความเร็วให้กับ member แต่ละคน [ 3 member ]
cherprang_speed = [2,2]
jennis_speed = [-3,4]
orn_speed = [3,-2]

# TO DO 4 : initialize pygame variable and create clock
pg.init()
clock = pg.time.Clock()
running = True 

# TO DO 5 : create screen [pygame.display.set_mode] and set caption [pygame.display.set_caption]
screen = pg.display.set_mode((width,height))


# Choose 3 members from BNK48 and create pygame object from  get_rect
# [ load , resize , get_rect ]

# Member 1 [size : (150 , 150) , center : (500 , 250) ]
cherprang_img = pg.image.load("source/BNK48/cherprang.png").convert_alpha()
cherprang_img = pg.transform.scale(cherprang_img, (150, 150))
cherprang_rect = cherprang_img.get_rect(center=(500,250))

# TO DO 6 : create object with attribute in each comment
# Member 2 [size : (100 , 100) , center : (250 , 120)]

jennis_img = pg.image.load("source/BNK48/jennis.png").convert_alpha()
jennis_img = pg.transform.scale(jennis_img, (100, 100))
jennis_rect = jennis_img.get_rect(center=(250,120))

# Member 3 [size : (120 , 120) , center : (800 , 400)]

orn_img = pg.image.load("source/BNK48/orn.png").convert_alpha()
orn_img = pg.transform.scale(orn_img, (120, 120))
orn_rect = orn_img.get_rect(center=(800,400))

while running:
    # TO DO 7 : set ให้ตัวเกมส์แสดงผลด้วยความเร็วที่เหมาะสม [clock.tick(...)]
    clock.tick(FPS)

    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
            pg.quit()

    if running:
        # TO DO 8 :ใส่สี background สีชมพู (screen.fill(...))
        screen.fill(pink)

        # TO DO 9 : ให้ member ทั้ง 3 คนเคลื่อนที่ตามทิศทางและความเร็วเป็นไปตาม speed ของแต่ละคน
        cherprang_rect = cherprang_rect.move(cherprang_speed)
        jennis_rect = jennis_rect.move(jennis_speed)
        orn_rect = orn_rect.move(orn_speed)


        # TO DO 10 : วาด text คำว่า "BNK48" [size : 250 , center :(width/2 , height/4), สีขาว]
        font_name = pg.font.match_font('arial') # กำหนดชื่อ Font
        font = pg.font.Font(font_name, 250) # กำหนดขนาด font
        text_surface = font.render("BNK48", True, white) # กำหนด Text และ สี
        text_rect = text_surface.get_rect() # แปลง Surface เป็น object
        text_rect.midtop = (width/2, height/2) # ระบุตำแหน่งของ text
        screen.blit(text_surface, text_rect)




        # TO DO 11 : เขียนเงื่อนไขไม่ให้ตกกรอบทุกด้านให้กับ member ทั้ง 3 คน
        if cherprang_rect.left < 0 or cherprang_rect.right > width:
            cherprang_speed[0] = -cherprang_speed[0]
        if cherprang_rect.top < 0 or cherprang_rect.bottom > height:
            cherprang_speed[1] = -cherprang_speed[1]
        if jennis_rect.left < 0 or jennis_rect.right > width:
            jennis_speed[0] = -jennis_speed[0]
        if jennis_rect.top < 0 or jennis_rect.bottom > height:
            jennis_speed[1] = -jennis_speed[1]
        if orn_rect.left < 0 or orn_rect.right > width:
            orn_speed[0] = -orn_speed[0]
        if orn_rect.top < 0 or orn_rect.bottom > height:
            orn_speed[1] = -orn_speed[1]
                



        # Special point ทำให้ลูกบอลชนกันแล้วเด้งในทิศตรงกันข้าม
        cherprang_center = [(cherprang_rect.left+cherprang_rect.right)/2,(cherprang_rect.top+cherprang_rect.bottom)/2]
        jennis_center = [(jennis_rect.left+jennis_rect.right)/2,(jennis_rect.top+jennis_rect.bottom)/2]
        orn_center = [(orn_rect.left+orn_rect.right)/2,(orn_rect.top+orn_rect.bottom)/2]
        if(abs(cherprang_center[0]-jennis_center[0])<=40 and abs(cherprang_center[1]-jennis_center[1])<=40):
            cherprang_speed[0]*=-1
            cherprang_speed[1]*=-1
            jennis_speed[0]*=-1
            jennis_speed[1]*=-1
        if(abs(cherprang_center[0]-orn_center[0])<=40 and abs(cherprang_center[1]-orn_center[1])<=40):
            cherprang_speed[0]*=-1
            cherprang_speed[1]*=-1
            orn_speed[0]*=-1
            orn_speed[1]*=-1
        if(abs(orn_center[0]-jennis_center[0])<=40 and abs(orn_center[1]-jennis_center[1])<=40):
            orn_speed[0]*=-1
            orn_speed[1]*=-1
            jennis_speed[0]*=-1
            jennis_speed[1]*=-1
        
        # TO DO 12 : เอาภาพของ member แต่ละคนใส่ลงใน object ของตนเอง
        screen.blit(cherprang_img, cherprang_rect)
        screen.blit(jennis_img, jennis_rect)
        screen.blit(orn_img, orn_rect)

        pg.display.flip()


