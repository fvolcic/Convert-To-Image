# Convert Anything To An Image!

ImageProcessor is a tool that allows anyone to convert anything to an image, or take that image and convert it back to its initial data!

Example text to image:
<p align="center">
  <img src="https://user-images.githubusercontent.com/59806465/143178641-acba6a91-1fd7-4aa9-8343-159628a9a546.png" />
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

To convert something to an image we use the following set of commands

```bash
./ImageProcessor -d -f [input-file] -o [output-file]
```

To convert something from an image (must have been an image created with ImageProcessor), we use the following command

```bash
./ImageProcessor -i -f [input-image]
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
