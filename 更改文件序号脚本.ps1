# 只重命名以数字开头的 LeetCode 题目文件，四位前导零格式
Get-ChildItem * | ForEach-Object {
    # 判断是否以数字开头，并且是 "数字.文件名" 格式
    if ($_.Name -match '^(\d+)\.(.+)$') {
        $num = [int]$matches[1]
        $rest = $matches[2]
        $newName = "{0:0000}.{1}" -f $num, $rest
        if ($_.Name -ne $newName) {
            Rename-Item $_ $newName
        }
    }
}