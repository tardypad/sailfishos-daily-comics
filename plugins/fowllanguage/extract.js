function(page) {
    var regex = / href="(/fowl-language/20[2-9][0-9]/[01][0-9]/[0-3][0-9])">/;
    var match = regex.exec(page);
    return match[1];
}
