function(page) {
    var regex = /<img id=comic[^>]*src=([^ ]*)/;
    var match = regex.exec(page);
    return match[1];
}
