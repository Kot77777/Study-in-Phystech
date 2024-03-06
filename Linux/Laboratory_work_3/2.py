import tkinter
from PIL import ImageTk, Image
from random import shuffle
sp = []
with open("RES.txt", "r") as file1:
    # итерация по строкам
    for line in file1:
        sp.append(list(map(int, line.split())))
class Canvas(tkinter.Canvas):
    def __init__(self, root, width, height):
        super().__init__(root, width = width, height = height)
        self.pack()

class Window(tkinter.Tk):
    def __init__(self, size, title):
        super().__init__()
        self.pixels = []
        self.geometry(size)
        self.title(title)
        self.canvas = Canvas(self, 480, 268)
        self.url = "pro2.jpeg"
        self.start()
        self.shellSort()
        self.mainloop()


    def start(self):
        self.set_image_attribute()
        rbg_image = self.convert_to_RGB()
        self.width, self.height = self.image.size
        pixel_index = 0
        for y in range(self.height) :
            for x in range(self.width):
                r,g,b = rbg_image.getpixel((x, y))

                colors = "%d,%d,%d\n" %(int(r),int(g),int(b))

                self.append_new_pixel_in_list((pixel_index, '#%02x%02x%02x' % ((r, g, b))))
                pixel_index+=1
        shuffle(self.pixels)
        self.draw_pixel()


    def append_new_pixel_in_list(self, value):
        self.pixels.append(value)

    def set_image_attribute(self):
        self.image = Image.open(self.url)

    def convert_to_RGB(self):
        return self.image.convert ("RGB")

    def shellSort(self):
        array = self.pixels
        increment = len(array) // 2
        while increment > 0:
            for startPosition in range(increment):
                self.gapInsertionSort(array, startPosition, increment)
            increment //= 2
            print("i")
            self .draw_pixel()

    def gapInsertionSort(self, array, low, gap):
        for i in range(low + gap, len(array), gap):
            currentvalue = array[i]
            position = i
        while position >= gap and array[position - gap][0] > currentvalue[0]:
            array[position] = array[position - gap]
            position = position - gap
        array[position] = currentvalue

    def draw_pixel(self):
        for y in range(self.height) :
            for x in range(self.width):
                left = x
                right = x + 1
                top = y
                bottom = y + 1
                color = self.pixels[y*self.width + x][1]
                self.draw_line(left, top, right, bottom, color)
        self.canvas .update()

    def draw_line(self, left, top, right, bottom, color, width=1):
        self.canvas.create_line(left, top, right, bottom, fill=color, width=width)

window = Window("480x268", "Сортируем картинку")



