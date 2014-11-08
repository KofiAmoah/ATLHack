Rails.application.routes.draw do

  get 'twilio/index'

  root :to => 'twilio#index'
  post '/send_sms' => 'twilio#send_sms'

end
