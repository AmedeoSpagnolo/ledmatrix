#!/usr/bin/env python
from samplebase import SampleBase
from rgbmatrix import graphics
import time

class SimpleSquare(SampleBase):
    def __init__(self, *args, **kwargs):
        super(SimpleSquare, self).__init__(*args, **kwargs)

    # SetPixel
    # canvas.SetPixel(x,y,r,g,b)

    # DrawLine
    # graphics.DrawLine(canvas, x0, y0, x1, y1, graphics.Color(255, 0, 0))

    # DrawCircle
    # graphics.DrawCircle(canvas, cx, cy, r, graphics.Color(255, 0, 0))

    # DrawText
    # graphics.DrawText(canvas, font, 2, 10, blue, "Text")

    # Fill
    # self.matrix.Fill(c, 0, 0)

    def run(self):
        canvas = self.matrix.CreateFrameCanvas()

        red     = graphics.Color(255, 0, 0)
        green   = graphics.Color(0, 255, 0)
        blue    = graphics.Color(0, 0, 255)
        white   = graphics.Color(255,255,255)
        font    = graphics.Font()
        font.LoadFont("fonts/4x6.bdf")

        # position
        # pos = offscreen_canvas.width

        # brightness
        max_brightness = self.matrix.brightness

        loop = [
          "man",
          "design",
          "branding",
          "advertising",
          "typography",
          "photography",
          "illustration",
          "editorial",
          "video",
          "print",
          "web"
        ]

        loop_temp = [
          "ma",
          "d",
          "b",
          "adr",
          "ty",
          "p",
          "ilr",
          "ed4",
          "v",
          "pr",
          "w"
        ]

        count       = 0
        marginleft  = 2
        margintop   = 10

        def ll(string):
            return sum([font.CharacterWidth(ord(c)) for c in string])

        while True:
            graphics.DrawText(canvas, font, marginleft, margintop, white, "FELD")
            graphics.DrawText(canvas, font, marginleft + ll("FELD"), margintop, white, loop_temp[count])
            graphics.DrawLine(canvas, marginleft + ll("FELD"), margintop + 1, marginleft + ll(loop_temp[count]+"FELD"), margintop + 1, white)
            canvas.SetPixel(marginleft + ll(loop_temp[count]+"FELD"), margintop - 1,255,255,255)
            time.sleep(1)

            count += 1
            count = count % len(loop_temp)

            canvas = self.matrix.SwapOnVSync(canvas)
            canvas.Clear()


# Main function
if __name__ == "__main__":
    simple_square = SimpleSquare()
    if (not simple_square.process()):
        simple_square.print_help()

# due led matrix
# animazione
