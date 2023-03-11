import cv2
import os

# 绝对路径
xml_path = "/"+os.path.abspath(__file__).strip("/general/using_xml.py")+"/data_file/data/"


def ReadXML(file_name, xml_data_name, xml_data):
    try:
        cv_file = cv2.FileStorage(xml_path+file_name, cv2.FILE_STORAGE_READ)
    except:
        print('打不开这个xml')
        return None

    xml_data = cv_file.getNode(xml_data_name).real()
    cv_file.release()
    return xml_data


def WriteXML(file_name, xml_data_name, xml_data,mode = False):
    try:
        if  mode:
            cv_file = cv2.FileStorage(xml_path+file_name, cv2.FILE_STORAGE_APPEND)
        else :
            cv_file = cv2.FileStorage(xml_path+file_name, cv2.FILE_STORAGE_WRITE)
    except:
        print('打不开这个xml')
        return False

    cv_file.cv_file.write(xml_data_name, xml_data)
    cv_file.release()
    return True
