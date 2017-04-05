int expr() {
  if (exps() && plus() && terme())
    return 1;
  else
    {
      if(terme())
        return 1;
    }
  return 0;
}

int terme() {
  if (terme() && fois() && facteur())
    return 1;
  else
    {
      if(facteur())
        return 1;
    }
  return 0;
}

int facteur(){
  
}
