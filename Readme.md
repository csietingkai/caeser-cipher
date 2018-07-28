# Caesar Cipher
Author: Ting-Kai Hu

Today Date: 2018-05-22

## Abstract
This is a simple practice for understand Casesar Cipher.

To understand more about Caesar Cipher: https://en.wikipedia.org/wiki/Caesar_cipher

I have finished the shift encode and keyword encode

## Usage
### Encoder (class)
use HashMap(unordered_map) to store all keys and values

to create an encoder: 
 ```
 // which means all alphabet will right shift 1-bit
 Encoder e(1);
 // then it create a right shift 1-bit encoder
 ```
or use keyword to create a encoder
 ```
 Encoder e("keyword");
 // the keys and values will be like:
 // a b c d e f g h i j k l m ...
 // | | | | | | | | | | | | | 
 // k e y w o r d e f g h i j ....
 ```
 
to encode a string :
 ```
 string str = e.process("the string you want ot encode");
 ```
### Decoder (class)
same as Encoder, but keys and values are in contrast

### Dictionary (class)
use a set to store all english vocabularys.

to check a vocabulary is english or not:
 ```
 Dictionary d;
 bool isEnglishOrNot = d.check(theWordYouWantToCheck);
 ```

### Checker (class)
use Decoder and Dictionary to determine the whole article is english or not

 ```
 Checker c
 string article;
 string result;
 bool isEnglishOrNot = c.isEnglish(article, &result);
 ```

or you use keyword encoder and decoder:
 ```
 ...
 Decoder d("keyword");
 bool isEnglishOrNot = c.isEnglish(article, &result, d);
 ```

