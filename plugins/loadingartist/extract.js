function(page) {
    var regex = /<img src=(\/comic[^\s]*.jpg)/;
    var match = regex.exec(page);
    return match[1];
}
