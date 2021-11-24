# Convert Anything To An Image!

ImageProcessor is a tool that allows anyone to convert anything to an image, or take that image and convert it back to its initial data!

Example text to image:
<p align="center">
  <img src="https://user-images.githubusercontent.com/59806465/143178641-acba6a91-1fd7-4aa9-8343-159628a9a546.png" />
</p>

Example audio of wind in a forest to an image:
<p align="center">
  <img src="https://user-images.githubusercontent.com/59806465/143290678-c998487a-b69e-4f48-8389-419e7a32fe5e.png" />
</p>

## Installation

First clone

```bash
git clone https://github.com/fvolcic/Convert-To-Image.git
```

Enter the directory, and then run

```bash
python3 build.py
```

This will create a binary titled 'ImageProcessor'

## Usage

When converting audio files, I recommend using .wav files. They are uncompressed, so the image will more closely reflect what you are actually hearing!

To convert something to an image we use the following set of commands

```bash
./ImageProcessor -d -f [input-file] -o [output-file]
```

To convert something from an image (must have been an image created with ImageProcessor), we use the following command

```bash
./ImageProcessor -i -f [input-image]
```

## Try It

This will return the Github Logo 

```bash
./ImageProcessor -i -f test-file.bmp
```

This will return a 1 second audio file of wind in a forst
```bash
./ImageProcessor -i -f wind.bmp
```

Or, drag and drop any file youd like into the directory and run this command to get an image: 
```bash
./ImageProcessor -d -f [YOUR-FILE-NAME] -o [myfile.bmp]
```

And to get the original data back, run
```bash
./ImageProcessor -i -f myfile.bmp
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
