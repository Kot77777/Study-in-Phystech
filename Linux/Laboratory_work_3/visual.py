import tkinter
import numpy as np
from PIL import ImageTk, Image
from random import shuffle
sp = []
with open("RES.txt", "r") as file1:
    # итерация по строкам
    for line in file1:
        sp.append(list(map(int, line.split())))
sp.append([i for i in range(128640)])
class Canvas(tkinter.Canvas):
    def __init__(self, root, width, height):
        super().__init__(root, width = width, height = height)
        self.pack()

class Window(tkinter.Tk):
    def __init__(self, size, title):
        super().__init__()
        self.pixels = []
        self.color = []
        self.num = []
        self.count = -1
        self.geometry(size)
        self.title(title)
        self.canvas = Canvas(self, 480, 268)
        self.url = "pro2.jpeg"
        self.start()
        self.Sort()
        self.mainloop()


    def start(self):
        self.set_image_attribute()
        rbg_image = self.convert_to_RGB()
        self.width, self.height = self.image.size
        pixel_index = (0)
        if (self.count == -1):
             for y in range(self.height) :
                 for x in range(self.width):
                     r,g,b = rbg_image.getpixel((x, y))

                     colors = "%d,%d,%d\n" %(int(r),int(g),int(b))
                     (self.color).append('#%02x%02x%02x' % ((r, g, b)))
                     (self.num).append(pixel_index)
                     self.append_new_pixel_in_list([pixel_index, '#%02x%02x%02x' % ((r, g, b))])
                     pixel_index += 1
        shuffle(self.pixels)
        self.draw_pixel()


    def append_new_pixel_in_list(self, value):
        self.pixels.append(value)

    def set_image_attribute(self):
        self.image = Image.open(self.url)

    def convert_to_RGB(self):
        return self.image.convert ("RGB")

    def Sort(self):
        my_dict = dict(zip(self.num, self.color))
        array = (self.pixels)
        for j in range(0, len(sp), 4):
            for i in range(len(array)):
                array[i][0] = sp[j][i]
                array[i][1] = my_dict[sp[j][i]]
                #array[i], array[*np.where(array == sp[j][i])[0][0]] = array[*np.where(array == sp[j][i])[0][0]],  array[i]
                #array[i][0] = sp[j][i]
            print("Смена")
            self.draw_pixel()

    def draw_pixel(self):
        for y in range(self.height) :
            for x in range(self.width):
                left = x
                right = x + 1
                top = y
                bottom = y + 1
                color = self.pixels[y*self.width + x][1]
                self.draw_line(left, top, right, bottom, color)
        self.canvas.update()

    def draw_line(self, left, top, right, bottom, color, width=1):
        self.canvas.create_line(left, top, right, bottom, fill=color, width=width)

window = Window("480x268", "Сортируем картинку")



