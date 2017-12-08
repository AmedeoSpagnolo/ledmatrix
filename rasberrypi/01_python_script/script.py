#!/usr/bin/env python
from samplebase import SampleBase


class SimpleSquare(SampleBase):
    def __init__(self, *args, **kwargs):
        super(SimpleSquare, self).__init__(*args, **kwargs)

    def pixel(self,canvas,x,y,r,g,b):
        canvas.SetPixel(x,y,r,g,b)

    def line(self,canvas,x,y,w,r,g,b):
        for i in range(0,w):
            canvas.SetPixel(x+i,y,r,g,b)

    def run(self):
        offset_canvas = self.matrix.CreateFrameCanvas()
        while True:

            # some amazing code
            self.line(offset_canvas,0,0,10,0,255,0)
            self.line(offset_canvas,0,2,32,0,255,0)
            self.line(offset_canvas,16,15,8,0,50,255)

            offset_canvas = self.matrix.SwapOnVSync(offset_canvas)


# Main function
if __name__ == "__main__":
    simple_square = SimpleSquare()
    if (not simple_square.process()):
        simple_square.print_help()
