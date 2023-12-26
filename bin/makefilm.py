import os

def main():
    # framepath = "meta/frames/"
    # frames = ""
    output = open("frametarget.txt", "w")

    if os.path.isfile("../meta/out.mp4"):
        os.remove("../meta/out.mp4")

    for i in range(350):
        output.write("file '../meta/frames/frame-{}.png'\nduration 0.04\n".format(i))
    

    output.close()
    
    os.popen("{}".format("ffmpeg -loglevel quiet -f concat -safe 0 -i frametarget.txt ../meta/out.mp4"))
    # os.remove("frametarget.txt") 


if __name__ == "__main__":
    main()
