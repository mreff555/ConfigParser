# Simple space delimited config file parser
## by Dan Feerst

I just wrote this a a thought experiement for something I was thinking about at work.  It expects a databse in the config directory but may be overridden when the constructor is invoked.  Values can retrieved with a string exactly
matching the name or in list form as a regex expression.  The database can be refreshed if the config is updated.

### Building

1. clone the repo and cd into directory;
2. create a build directory, and cd into that
3. run cmake ..; make
```
git clone git@github.com:mreff555/ConfigParser.git
mkdir -P ConfigParser/build
cd ConfigParser/build
cmake ..
make
```

### TODO:
- The parser should probably be whitespace agnostic.
