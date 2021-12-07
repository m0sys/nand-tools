# Preserve your sanity - Convert XML to JSON.
# Author: m0sys
# Date: 2021/12/7

import json
import xmltodict
import argparse


def xml2json(xml_fname, indent):
    with open(xml_fname, "r") as xml_file:
        data = xmltodict.parse(xml_file.read())
        xml_file.close()
        json_obj = json.dumps(data, indent=indent)

    with open(_extract_path_fname(xml_fname)+".json", "w") as jfile:
        jfile.write(json_obj)
        jfile.close()


def _extract_path_fname(path):
    pos_last_slash = path.rfind("/")
    pos_ext = path.rfind(".xml")
    return path[0:pos_ext]


# Runner
if __name__ == "__main__":
    s = "../projects/10/Square/Main.xml"
    parser = argparse.ArgumentParser(description='Preserver your sanity by converting XML to JSON with this simple command-line tool! ✨')
    parser.add_argument('--version', action='version', version='%(prog)s 0.1')
    parser.add_argument('xml_path', action='store', help='Path to the XML file which will be converted into JSON and stored as a .json file in the same directory as the XML file.')
    parser.add_argument('--json_indent', action='store', help='Indentation level of the generated JSON (default=2)', type=int, default=2)
    args = parser.parse_args()
    xml2json(args.xml_path, args.json_indent)
    print("Conversion is succesful!")
