# **Tower Defense**
## **Video demo** : [Drive link](https://drive.google.com/file/d/1OFSKsEE1SBk7E3eio2TZ0CTekAB1_QS4/view?usp=drive_link)
## **Table of Content**
-   [**Tower Defense**](#tower-defense)
    - [**Video Demo**](#video-demo)    
    - [**Table of Contents**](#table-of-contents)
    - [**Giới thiệu Game**](#giới-thiệu-game)
    - [**Cách tải game**](#cách-tải-game)
    - [**Hướng dẫn chơi**](#hướng-dẫn-chơi)
    - [**Kỹ thuật lập trình**](#kỹ-thuật-lập-trình)
    - [**Nguồn tham khảo**](#nguồn-tham-khảo)
    

## **Giới thiệu Game**
- Là 1 game dạng Tower Defense. Nhiệm vụ của bạn là ngăn không cho quái vật xâm nhập nhà chính , tích lũy điểm số cao 
nhất có thể cho đến khi thua cuộc .

## **Cách tải Game**
1. Nếu có codeblocks thì git clone project về ( chạy bằng code blocks)
2. giải nén và chạy theo file exe theo tệp [zip](https://github.com/mingg23805/sdl2_game_UET_INT2215/blob/main/Data/Images/Tile%20Wall.bmp)

## **Hướng dẫn chơi**
1. Khi bắt đầu game hoặc khi đánh xong quái của level đó, bạn có 5 giây để đợi quái ra .
2. Cách thao tác trong game 
 - Bấm phím 1 để chuyển chế độ xây tường    <img src= https://github.com/mingg23805/sdl2_game_UET_INT2215/blob/main/Data/Images/Tile%20Wall.bmp>
 - Bấm phím 2 để chuyển sang chế độ xây trụ  <img src=https://github.com/mingg23805/sdl2_game_UET_INT2215/blob/main/Data/Images/Turret%20Under.bmp>
 - Bấm chuột trái để xây tường hoặc trụ tùy theo bạn đang ở chế độ nào
 - Bấm chuột phải để xóa bỏ tường và trụ ở vị trí đó 

## **Kỹ thuật lập trình**
### ***Phát triển trên nền tảng:***
- IDE CodeBlocks 20.03
- Ngôn ngữ lập trình : C++
- Thư viện: SDL2 cùng các thư viện chính của C++
- Extension của SDL2:
    - SDL_Image: Hỗ trợ xử lý hình ảnh
    - SDL_Mixer: Hỗ trợ xử lý âm thanh
    - SDL_Ttf: Hỗ trợ xử lý fonts chữ
### ***Các kỹ thuật lập trình:***
- Gồm tất cả các kỹ thuật cơ bản:
    - Vòng lặp, cấu trúc rẽ nhánh,...
    - Con trỏ,con trỏ thông minh , vector, string,...
    - Class: Tạo, hủy, member function.
    - Đọc viết file: fstream
    - Tách file quản lý code.
    - Kỹ thuật duyệt mảng, sinh số ngẫu nhiên.
    - Các kỹ thuật, syntax của SDL.
    - Kỹ thuật giải phóng bộ nhớ.
    - Kỹ thuật xử lý thời gian .
    - thuật toán tìm đường 
  

## **Về source code game:**
- Folder Data chứa 3 folder con dùng để lưu các thông tin của game :
    - Fonts:  chứa font chữ.
    - Images: chứa các hình ảnh của game.
    - Sounds: chứa các sound effect của game.
- (Để thuận tiện thì từ giờ file.h và file.cpp sẽ được gọi chung là file)  
- Fontloader, MixerLoader, FontLoader:
  -  là 3 chương trình dùng để tải các tài nguyên như  hình ảnh, âm thanh, font 
   - Sử dụng các lệnh cơ bản của SDL để load các tài nguyên nói trên  và std::unordered_map để lưu trữ chúng
- Level:
  - là file dùng để tính toán những thứ cơ bản của game bao gồm :
     + targetPos + số ô theo phương x + số ô theo phương Y 
     + Các loại ô như: ô không thể xây, tường , ô sinh địch 
     + Tính toán đường đi ngắn nhất của các unit
 - Unit + turret + projectile : 
   - là các file xây dựng các class cơ bản của game như unit, turret và đạn 
   - xử lý các sự kiện cơ bản của game như va chạm, bắn đạn 
 - game:
    - quản lý các class cơ bản của game
    - quản lý các tài nguyên như Hp  hay điểm
    - xử lý các sự kiện trong game như click chuột hay bấm phím 
    - render những thứ cần hiển thị .    
    - quản lý hoạt động game .
  - Vector2D: quản lý vị trí theo hệ tọa độ Oxy 
  - timer: quản lý thời gian của game 
## **Nguồn tham khảo**  
 -[lazyfoo](https://lazyfoo.net/tutorials/SDL/)

 -[youtube](https://www.youtube.com/@funneractic)
