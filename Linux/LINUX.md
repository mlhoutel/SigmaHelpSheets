# :penguin: LINUX SHEET
[Return to the menu](../README.md)
# Fast Help
Instruction | Command
------------ | -------------
**Move directory** | ```cd directory_name```
**Current folder** | ```pwd```
**Command location** | ```which command_name```
**List folders** | ```ls```</br>```[-l (detail)][-a (hidden)][-F (type)][-h (size)][-t (date)][-r (reverse)]```
**Disk usage** | ```du```</br>```[-h (size)][-a (all)][-s (sum)]```
**Display all file** | ```cat file_name```</br>```[-n (lines)]```
**Display page file** | ```less file_name```</br>```[SPACE (scroll)][ENTER (next)][B (back)][Q (quit)][/text_to_find (find) + n(next)/N(back)]```
**Display part file** | ```head file_name/tail file_name```</br>```[-n 10 (lines)][-f (follow)]```
**Create file** | ```touch file_name ```</br>```[second_file_name...]```
**Create directory** | ```mkdir folder_name```</br>```[-p (path folders)]```
**Copy file** | ```cp file_name copy_name```</br>```[*.jpg (wildcard)][-R (recursive)]```
**Move file** | ```mv file_name folder_name/```</br>```[*.jpg (wildcard)]```
**Rename file** | ```mv file_name new_file_name```
**Remove file** | ```rm file_name ```</br>```[second_file_name...][-i (ask)][-f (force)][-v (verbose)][-r (recursive)]```
**Link file** | ```ln file_name target_name```
## Linux directory
```
/                                               *Root directory*  
├───bin                                         *Users programs*  
├───boot                                        *System booting*  
├───dev                                         *Devices (ex:CD)*  
├───etc                                         *Config folder*   
├───home                                        *Users folders*  
│     ├───userA  
│     └───userB  
├───lib                                         *Shared libraries*  
├───media                                       *Medias (ex:USB)*  
├───mnt                                         *Temporary medias*  
├───opt                                         *Programs add-ons*  
├───proc                                        *System infos*  
├───root                                        *Root user folder*  
├───sbin                                        *System programs*  
├───tmp                                         *Temporary folder*  
├───usr                                         *Users programs*  
└───var                                         *Datas and Logs*  
```
