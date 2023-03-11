import sys

sys.path.insert(0, sys.path[0]+"/../general")
sys.path.append(".")
sys.path.append("..")

import  using_xml
from using_xml import ReadXML,WriteXML

class Demo:

    is_print = True

    def __init__(self) -> None:
        print("__init__初始化\n")
    def DemoPrint(self, *args) -> bool:
        """_summary_

        Returns:
            bool: _description_
        """
        if (self.is_print == False):
            return False
        else:
            print("python打印\n", args)
            print("\n")
            return True


demo = Demo()
demo.DemoPrint(123, 123, "\n\n\n")
data = 0
data = ReadXML("swap.xml","slParams_camHeight",data)
print(data)
