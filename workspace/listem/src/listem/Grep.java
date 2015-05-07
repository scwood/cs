package listem;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Grep extends FileScanner implements IGrep {
  
  private Map<File, List<String>> fileMap = new HashMap<File, List<String>>();
  private String substringSelectionPattern = null;

  @Override
  public Map<File, List<String>> grep(File directory,
      String fileSelectionPattern, String substringSelectionPattern,
      boolean recursive) {
    clear();
    this.substringSelectionPattern = substringSelectionPattern;
    processDir(directory, fileSelectionPattern, recursive);
    return fileMap;
  }

  @Override
  void processLine(File file, String line) {
    Pattern pattern = Pattern.compile(substringSelectionPattern);
    Matcher matcher = pattern.matcher(line);
    if (matcher.find()) {
      if (fileMap.containsKey(file)) {
        fileMap.get(file).add(line);
      } else {
        List<String> newList = new ArrayList<String>();
        newList.add(line);
        fileMap.put(file, newList);
      }
    }
  }
  
  void clear() {
    fileMap.clear();
    substringSelectionPattern = null;
  }
  
}