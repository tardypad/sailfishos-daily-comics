function(page) {
    var regex = /<media:content url="([^"]*piratemikecomics.files.wordpress.com\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
