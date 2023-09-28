function(page) {
    var regex = /<img[^>]* data-orig-file="([^"?]+\.[-+_0-9A-Za-z]+)["?][^>]* class/;
    var match = regex.exec(page);
    return match[1];
}
