class Demo:
    is_print = True

    def __init__(self) -> None:
        print("__init__初始化\n")

    def print(self, *args) -> bool:
        if (self.is_print == False):
            return False
        else:
            print("python打印\n", args)
            print("\n")
            return True


# if __name__ == "__main__":
demo = Demo()
demo.print(123, 123,"\n\n\n")

